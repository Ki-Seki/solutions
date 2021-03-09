#include <iostream>
#include <cmath>
#define MAXN 17

bool is_prime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= (int) sqrt(n * 1.0); i++)
        if (n % i == 0)
            return false;
    return true;
}

int get_reverse(int n, int d)
{
    // 转换为 d 进制的数组 arr_n
    int arr_n[MAXN], len = 0;
    for (; n > 0; n /= d)
        arr_n[len++] = n % d;

    // 逆序加权相加求 reverse 后的值
    int ans = 0;
    for (int i = 0; i < len; i++)
        ans += arr_n[i] * (int) pow(d, len - i - 1);
    return ans;
}

int main()
{
    int n, d;
    while (scanf("%d %d", &n, &d) && n > 0)
    {
        if (is_prime(n) && is_prime(get_reverse(n, d)))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}