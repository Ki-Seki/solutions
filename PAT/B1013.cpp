/*
 * hint:
 * 测试点0，1：考察格式，要求 10 个一行输出
 * 
 * 找 n （较大）以内的素数，素数表大概开 n/10 即可
 * 
 * some primes:
 * 10th     29
 * 100th    541
 * 1000th   7919
 * 10000th  104729
 * 100000th 1299709
*/

#include <iostream>

const int maxn = 1000000;
int prime[maxn], p_len = 0;
bool not_prime[maxn * 20] = {};

void find_prime(int n)
{
    for (int i = 2; i <= n; i++)
        if (not_prime[i] == 0)
        {
            prime[p_len++] = i;
            for (int j = i + i; j <= n; j += i)
                not_prime[j] = true;
        }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    find_prime(1000000);
    int cnt = 1;
    for (int i = n - 1; i < m; i++)
        if (i == m - 1)
            printf("%d", prime[i]);
        else if (cnt % 10 == 0)
            printf("%d\n", prime[i]), cnt++;
        else
            printf("%d ", prime[i]), cnt++;
}