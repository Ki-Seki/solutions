/*
 * hint:
 * 测试点2：若库存量和总价格不用 double 来定义，则会报错
*/
#include <iostream>
#include <algorithm>
#define MAXN 1005

struct Mooncake{
    double storage, value, price;
} mc[MAXN];

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%lf", &mc[i].storage);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &mc[i].value);
        mc[i].price = 1.0 * mc[i].value / mc[i].storage;
    }
    std::sort(mc, mc + n, cmp);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].storage <= d)
        {
            d -= mc[i].storage;
            profit += mc[i].value;
        }
        else
        {
            profit += d * mc[i].price;
            break;
        }
    }
    printf("%.2f", profit);
    return 0;
}