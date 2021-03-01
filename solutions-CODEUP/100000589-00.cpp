#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a%b));
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int n, m, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ans = 1;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            ans = lcm(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}