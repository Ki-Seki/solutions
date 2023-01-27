#include <iostream>
#define S2G 17
#define K2S 29
using namespace std;

int main()
{
    unsigned long long g1, s1, k1, g2, s2, k2, g, s, k, sum1, sum2, sum;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
    sum1 = g1 * S2G * K2S + s1 * K2S + k1;
    sum2 = g2 * S2G * K2S + s2 * K2S + k2;
    sum = sum1 + sum2;
    g = sum / K2S / S2G;
    s = sum / K2S % S2G;
    k = sum % K2S;
    cout << g << '.' << s << '.' << k << endl;
    return 0;
}