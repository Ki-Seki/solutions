#include <stdio.h>
#include <math.h>
#define MAXN 50//00005
#define MOD 1000007
int dp[MAXN] = {0}, n;

int dfs(int st, int max)
{
    if (st == 1 || st == 0)
    {
        dp[st] = 1;
        return 1;
    }
    int ans = 0;
    for (int exp = log2(st); exp >= 0; exp--)
    {
        int tmp = pow(2, exp);
        if (tmp > max) continue;
        // if (dp[st-tmp] != 0) dp[st] *= dp[st-tmp];
        // else 
        ans += dfs(st - tmp, tmp>(st-tmp) ? st-tmp : tmp);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    n = 3;
    printf("%d\n", dfs(n, n));
    return 0;
}