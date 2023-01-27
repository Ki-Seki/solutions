/*
 * hint:
 * 证明：对于已经拼接好的最小序列，对任意 0 ≤ i < j ≤ n - 1，有 number[i] + number[j] <= number[j] + number[i]（ + 表示数字拼接）。反证法证明如下：
 * 假设结论反面成立：存在 0 ≤ i < j ≤ n - 1，使得number[i] + number[j] > number[j] + number[i]
 * 易知，此时，只要 i 号和 j 号数字段交换位置就可以使序列更小，因此与前提冲突。
 * 假设不成立，原结论正确。
*/

#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 10005
using namespace std;

string number[MAXN];

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n, cmp);
    bool time_to_output = false;
    for (int i = 0; i < n; i++)
    {
        int len = number[i].length();
        for (int j = 0; j < len; j++)
            if (time_to_output)
                cout << number[i][j];
            else if (! time_to_output && number[i][j] != '0')
            {
                time_to_output = true;
                cout << number[i][j];
            }
    }
    if (! time_to_output) cout << '0';
    return 0;
}