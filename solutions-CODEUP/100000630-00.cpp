#include <bits/stdc++.h>
using namespace std;

// adj_matrix[i][j] == 1 represents rec i can be contained into rec j
int adj_matrix[1005][1005];
int rec[105][2];
int dp[1005];

int dfs(int x, int n)
{
    if (dp[x] > 0) return dp[x];
    dp[x] = 1;
    for (int i = 0; i < n; i++)
        if (adj_matrix[x][i])
            dp[x] = max(dp[x], 1 + dfs(i, n));
    return dp[x];
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        // Input and initialize.
        memset(dp, 0, sizeof(dp));
        memset(adj_matrix, 0, sizeof(adj_matrix));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &rec[i][0], &rec[i][1]);
            if (rec[i][0] > rec[i][1]) swap(rec[i][0], rec[i][1]);
        }

        // Calculate adj_matrix.
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (rec[i][0]<rec[j][0] && rec[i][1]<rec[j][1])
                    adj_matrix[i][j] = 1;
        
        // Calculate dp[]
        for (int i = 0; i < n; i++)
        {
            bool is_start = true;
            for (int j = 0; j < n; j++)
                if (adj_matrix[j][i])
                {
                    is_start = false;
                    break;
                }
            if (is_start) dfs(i, n);
        }

        // Output answer.
        int M = -1;
        for (int i = 0; i < n; i++)
            if (dp[i] > M)
                M = dp[i];
        printf("%d\n", M);
    }
    return 0;
}