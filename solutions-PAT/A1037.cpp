/*
 * hint:
 * 测试点1，5：考察当 coupon 中正数（负数）和 product 中正数（负数）个数相等时的处理
*/
#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;

long long coupon[MAXN], product[MAXN];

bool cmp(long long a, long long b)
{
    return a > b;
}

int main()
{
    int nc, np;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++)
        scanf("%lld", &coupon[i]);
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
        scanf("%lld", &product[i]);
    long long ans = 0;
    int minlen = min(nc, np);
    sort(coupon, coupon + nc);
    sort(product, product + np);
    for (int i = 0; i < minlen; i++)
        if (coupon[i] < 0 && product[i] < 0)
            ans += coupon[i] * product[i];
        else break;
    sort(coupon, coupon + nc, cmp);
    sort(product, product + np, cmp);
    for (int i = 0; i < minlen; i++)
        if (coupon[i] > 0 && product[i] > 0)
            ans += coupon[i] * product[i];
        else break;
    printf("%d", ans);
    return 0;
}