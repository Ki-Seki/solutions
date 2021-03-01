/*
 * hint:
 * 测试点 2：考察 double 类型多次累加造成的误差
 * 经测试，每个小数位数不超过 3 位，因此可用 long long 保存
*/

#include <iostream>

int main()
{
    
    int n;
    double tmp;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &tmp);
        ans += (long long) (tmp * 1000) * (n + 1 - i) * i;
    }
    printf("%.2f", ans / 1000.0);
    return 0;
}