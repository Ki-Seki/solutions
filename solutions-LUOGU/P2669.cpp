#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    scanf("%d", &k);
    int n = sqrt(double(2 * k)+0.25) - 0.5;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i * i;
    ans += (k - n * (n+1) / 2) * (n+1);
    printf("%d\n", ans);
    return 0;
}