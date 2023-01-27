/*
 * hint:
 * 
 * 测试点 1：考察 m > n
 * 测试点 2，3：考察 m % n == 0
 * 
 * 本题使用两种方法
 * 方法一：打开思路，不要被题目限制！直接输出即可
 * 方法二：模拟。使用最大公因数优化算法
*/

// // 直接输出
// #include <iostream>

// using namespace std;

// int main()
// {
//     int a[105], n, m;
//     cin >> n >> m;
//     m %= n;
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = n - m; i < n; i++) cout << a[i] << ' ';
//     for (int i = 0; i < n - m - 1; i++) cout << a[i] << ' ';
//     cout << a[n-m-1];
//     return 0;
// }

// 模拟
#include <iostream>
#define MAXN 105

int arr[MAXN];

int gcd(int n, int m)
{
    return (m ? gcd(m, n%m) : n);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    m %= n;
    if (m != 0)
    {
        int d = gcd(n, m);
        for (int i = n - m; i <= n - m + d - 1; i++)
        {
            int tmp = arr[i];
            for (int j = (i + n - m) % n; j != i; j = (j + n - m) % n)
                arr[(j + m) % n] = arr[j];
            arr[(i + m) % n] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
        printf(i ? " %d" : "%d", arr[i]);
    return 0;
}