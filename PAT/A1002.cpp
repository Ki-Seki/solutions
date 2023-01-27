#include <iostream>
#define MAXN 1005
using namespace std;

double poly[MAXN] = {0};
int main()
{
    int k, exp, count = 0;
    double coe;

    // 输入兼计算多项式和
    for (int j = 0; j < 2; j++)
    {
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %lf", &exp, &coe);
            if (coe != 0) poly[exp] += coe;
        }
    }

    // 计算 count：因为读取时同时计算需要判断正负抵消、读取为 0 等情况，遂单独计算
    for (int i = 0; i < MAXN; i++) if (poly[i] != 0.0) count++;

    // 输出
    printf("%d", count);
    for (int i = MAXN - 1 ;i >= 0; i--)
        if (poly[i] != 0) printf(" %d %.1lf", i, poly[i]);
    return 0;
}