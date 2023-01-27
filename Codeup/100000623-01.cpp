/*
 * hint:
 * 此题必须用暴力法求解，
 * 因为要求在所有可能解中找到最小的一个，那就必须得用贪心，而贪心求拓扑排序，只能是暴力的
 * VITAL 行十分重要，他等价于在 main 函数中的循环体开头初始化 adj 变量
*/
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 550

using namespace std;

int n, m;
vector<int> adj[MAXN];
int in_degree[MAXN];
int ans[MAXN], num;

void topological_sort()
{
    // n traverses, find an answer's vertex each loop
    for (int i = 1; i <= n; i++)
    {
        // find first unvisited vertex with 0 in-degree
        for (int j = 1; j <= n; j++)
            if (in_degree[j] == 0)
            {
                ans[num++] = j;
                in_degree[j]--;
                for (int k = 0; k < adj[j].size(); k++)
                    in_degree[adj[j][k]]--;
                break;
            }
        adj[ans[num-1]].clear();  // VITAL
    }
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF && n != 0)
    {
        memset(in_degree, 0, sizeof(in_degree));
        num = 0;
        for (int i = 0; i < m; i++)
        {
            int p1, p2;
            scanf("%d %d", &p1, &p2);
            adj[p1].push_back(p2);
            in_degree[p2]++;
        }
        topological_sort();
        for (int i = 0; i < n; i++)
            printf(i == n - 1 ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}