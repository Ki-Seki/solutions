#include <iostream>
#define S2G 17
#define K2S 29
using namespace std;

int main()
{
    int g1, s1, k1, g2, s2, k2, sign, g, s, k;
    unsigned long long sum1, sum2, diff;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    sum1 = g1 * S2G * K2S + s1 * K2S + k1;
    sum2 = g2 * S2G * K2S + s2 * K2S + k2;
    sign = (sum1 < sum2) * 2 - 1;  // 区间扩大法
    diff = sign * (sum2 - sum1);
    g = diff / K2S / S2G;
    s = diff / K2S % S2G;
    k = diff % K2S;
    cout << sign * g << '.' << s << '.' << k;
    return 0;
}