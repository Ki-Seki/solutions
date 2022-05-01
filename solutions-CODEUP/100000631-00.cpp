/*
 * hint: 
 * 未解决
*/
#include <bits/stdc++.h>
#define MAXV 20005
using namespace std;

int w[MAXV];
int dp[MAXV][MAXV];  // dp[i][v] 代表前 i 个物品装进空间为 v 的箱子的最小剩余空间 
int v, n;  // 总容量，物品个数

int main()
{
	while(scanf("%d%d", &v, &n)==2)
	{
        memset(w, 0, sizeof(w));
        memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 1; i <= n; i++)  // 遍历物品 
			for (int j = 1; j <= v; j++)  // 遍历重量 
				{
					// 边界 
					if (i == 1 && j > w[i])
						dp[i][j] = j - w[i];
					if (i == 1 && j < w[i])
						dp[i][j] = j;
					// 状态转移方程
					if (i != 1)
                    {
                        if (j >= w[i]) dp[i][j] = min(dp[i-1][v], dp[i-1][j-w[i]]);
                        else dp[i][j] = dp[i-1][v];
                    }
				}
        		for (int i = 1; i <= n; i++)  // 遍历物品 
			{for (int j = 1; j <= v; j++)  // 遍历重量 
                printf("%d ", dp[i][j]);
                printf("\n");}
		int ans = MAXV;
		for (int i = 1; i <= n; i++)
			if (dp[i][v] < ans)
				ans = dp[i][v];
		printf("%d\n", ans);
	}
	
	return 0;
}