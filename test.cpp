// 双指针的方法，效率：O(n)
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define MAXN 100005
using namespace std;
typedef long long LL;

LL arr[MAXN];

// 根据 seed 生成随机的 n 个随机数
void gen_data(LL data[], unsigned seed, LL n)
{
    srand(seed);
    for (LL i = 0; i < n; i++)
        data[i] = rand();
}

void output_array(LL data[], LL n)
{
    for (LL i = 0; i < n; i++)
        printf("%lld ", data[i]);
    printf("\n");
}

int main()
{
    LL n = 1000, p = 459;
    gen_data(arr, p, n); output_array(arr, n);
    sort(arr, arr + n); output_array(arr, n);
    int max_len = -1, pi = 0, pj = 0;
    while (pj < n)
    {
        while (pj < n && arr[pj] <= (LL) arr[pi] * p) pj++;
        if (max_len < (pj - pi)) max_len = pj - pi;
        pi++;
    }
    printf("%d", max_len);
    return 0;
}