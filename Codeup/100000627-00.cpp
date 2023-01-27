#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

int n, a[MAXN] = {0}, dp[MAXN] = {0};

int main()
{
    while (scanf("%d", &n) == 1)
    {
        // input
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        // calculate dp array
        // dp[i] = max{1, dp[j]+1}, j < i, a[j] < a[i]
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[j] < a[i] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
        }
        // get max{dp}
        int M = -1;
        for (int i = 1; i <= n; i++)
            if (dp[i] > M)
                M = dp[i];
        printf("%d\n", M);
    }
    return 0;
}