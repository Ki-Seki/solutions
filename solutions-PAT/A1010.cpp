/*
 * hint:
 * 1. 注意二分查找时：left，right 的确定问题
 * 2. 注意要找的目标进制数是可能大于 36 进制的
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;

LL radix2dec(string x, int radix)
{
    LL ans = 0;
    int len = x.length(), digit;
    for (int i = 0; i < len; i++)
    {
        if (x[i] >= 'a' && x[i] <= 'z')
            digit = x[i] - 'a' + 10;
        else
            digit = x[i] - '0';
        ans += digit * (LL) powl(radix, len - i - 1);
    }
    return ans;
}

LL maxDigit(string num)
{
    int len = num.length();
    char dig = 0;
    for (int i = 0; i < len; i++)
        if (num[i] > dig)
            dig = num[i];
    return (dig >= 'a' ? dig - 'a' + 10 : dig - '0');
}

int binarySearch(LL left, LL right, string n2, LL n1_dec)
{
    LL mid, mid_value;
    while (left <= right)
    {
        mid = (left + right) / 2;
        mid_value = radix2dec(n2, mid);
        if (mid_value == n1_dec)
            return mid;
        else if (mid_value > 0 && mid_value < n1_dec)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    // input & init
    string n1, n2;
    int tag;
    LL radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (n1 == n2)  // special judge
    {
        printf("%d", radix);
        return 0;
    }
    if (tag == 2) swap(n1, n2);  // ensure n1 is the src while n2 is the des

    // calculate the n1 in decimal
    LL n1_dec = radix2dec(n1, radix);

    // find the rough range of n2's radix for binarySearch
    LL left = maxDigit(n2) + 1, right = max(left, n1_dec) + 1;

    // binarySearch
    int des_radix = binarySearch(left, right, n2, n1_dec);

    // output answer
    printf(des_radix == -1 ? "Impossible" : "%d", des_radix);
    return 0;
}