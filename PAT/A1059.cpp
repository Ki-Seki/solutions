/*
 * hint:
 * 
 * 测试点 3：考察特殊值，当 n == 1 时，要特判
 * 
 * 经测试，素数表开到 10000 足够应付此题
 * 
 * 质数因子数组开到 10 即可，因为 ↓
 * 6469693230 = 2 * 3 * ... * 29 （前 10 个素数的乘积）
 * 2147483647 = 2 ^ 31 - 1
 * 
 * 启示：
 * 用到素数表时，若使用筛法，则要定义素数表数组，筛选数组，其关系 ↓
 * 素数表数组大小 * 10 ≈ 筛选数组大小 （尤其 n -> ∞）
*/
#include <iostream>
#include <cmath>
#define MAXN 10000 // 素数表大小

struct {
    int p, k;
} factor[10];

int prime[MAXN + 5],  // 素数表数组
    p_len = 0;
bool not_prime[MAXN * 20] = {};  // 筛选数组
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
    find_prime(MAXN);
    int n;
    scanf("%d", &n);
    if (n == 1) {printf("1=1"); return 0;}  // special judge
    int len = 0, tmp = n;
    for (int i = 0; i < p_len; i++)
    {
        if (prime[i] <= (int) sqrt(n * 1.0) && n % prime[i] == 0)
        {
            factor[len].p = prime[i];
            factor[len].k = 0;
            while (n % prime[i] == 0)
            {
                factor[len].k++;
                n /= prime[i];
            }
            len++;
        }
    }
    if (n != 1)
    {
        factor[len].p = n;
        factor[len].k = 1;
        len++;
    }
    printf("%d=", tmp);
    for (int i = 0; i < len; i++)
    {
        if (factor[i].k == 1)
            printf("%d", factor[i].p);
        else
            printf("%d^%d", factor[i].p, factor[i].k);
        if (i != len - 1) printf("*");
    }
    
}