/*
 * hint:
 * DP 算法最好选择从 1 开始计数，因为下标为 0 时往往是边界
*/

#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

char x[MAXN], z[MAXN];
int n, dp[MAXN][MAXN] = {0};

int main()
{
    while (scanf("%s %s", x+1, z+1) == 2)
    {
        int lx = strlen(x+1), lz = strlen(z+1);
        for (int i = 1; i <= lx; i++)
            for (int j = 1; j <= lz; j++)
            {
                if (x[i] == z[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        printf("%d\n", dp[lx][lz]);
        memset(x, '\0', sizeof(x));
        memset(z, '\0', sizeof(z));
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}