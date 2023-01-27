#include <bits/stdc++.h>
#define MAXN 105
int offset_x[5] = {1, 0, 1, 1, -1}, offset_y[5] = {0, 1, 1, -1, 1};  // 5 个行进方向
bool matrix[MAXN][MAXN] = {0}, visited[MAXN][MAXN] = {0};
int n, m, ans = 0, infect = 0;
char tmp[MAXN];

void dfs(int i, int j)
{
    if (1 <= i && i <= n && 1 <= j && j <= n)
    {
        if (visited[i][j] == false && matrix[i][j] == 1)
        {
            matrix[i][j] = 0; infect--;
            for (int l = 0; l < 5; l++)
                for (int m = 0; m < 5; m++)
                    dfs(i+offset_x[l], j+offset_y[m]);
        }
        visited[i][j] = true;
    }
}

int main()
{
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", tmp+1);
        for (int j = 1; j <= m; j++)
        {
            if (tmp[j] == '1')
            {
                matrix[i][j] = 1;
                infect++;
            }
        }
    }
    while (infect != 0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        if (infect == 1)
        {
            ans++;
            infect = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}