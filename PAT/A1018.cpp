/*
 * hint:
 * dfs 算法要注意：如果节点之间存在依赖关系（如本题的），需要记得依赖性的变量的缓存和复原
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 505
#define INF 0x3fffffff

int c, n, s, m;

int vertex[MAXN] = {};  // stores current capacity of i
int edge[MAXN][MAXN];  // stores time between i and j
bool is_visited[MAXN] = {};

int min_time[MAXN];
std::vector<int> pre[MAXN];

std::vector<int> min_path, tmp_path;
int min_bring = INF, tmp_bring = 0;
int min_fetch = INF, tmp_fetch = 0;

void dijkstra()
{
    // init
    min_time[0] = 0;
    // n+1 times loop
    for (int i = 0; i <= n; i++)
    {
        // find u
        int u = -1, min = INF;
        for (int j = 0; j <= n; j++)
            if (min_time[j] < min && is_visited[j] == false)
            {
                u = j;
                min = min_time[j];
            }
        // meet the end
        if (u == -1) break;
        // visit u
        is_visited[u] = true;
        // update u's neighbors
        for (int j = 0; j <= n; j++)
            if (edge[u][j] < INF && is_visited[j] == false)
                if (min_time[u] + edge[u][j] < min_time[j])
                {
                    min_time[j] = min_time[u] + edge[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if (min_time[u] + edge[u][j] == min_time[j])
                    pre[j].push_back(u);
    }
}

void dfs(int s)
{
    // recursion boundary
    if (s == 0)
        if (tmp_bring < min_bring ||
            tmp_bring == min_bring && tmp_fetch < min_fetch)
        {
            min_path = tmp_path;
            min_bring = tmp_bring;
            min_fetch = tmp_fetch;
        }
    // traverse s's pres
    for (int i = 0; i < pre[s].size(); i++)
    {
        // cache status
        int cached_tmp_bring = tmp_bring, cached_tmp_fetch = tmp_fetch;

        // update status
        tmp_path.push_back(s);
        if (vertex[s] < 0)  // miss (-vertex[s]) bikes here
            tmp_bring += -vertex[s];
        else if (vertex[s] > 0)  // surplus vertex[s] bikes here
        {
            // cnt bikes needed to transfer from vertex[s] to ahead
            int cnt = std::min(vertex[s], tmp_bring);
            tmp_bring -= cnt;
            tmp_fetch += vertex[s] - cnt;
        }

        // recursion
        dfs(pre[s][i]);

        // restore status
        tmp_path.pop_back();
        tmp_bring = cached_tmp_bring;
        tmp_fetch = cached_tmp_fetch;
    }

}

int main()
{
    std::fill(edge[0], edge[0] + MAXN * MAXN, INF);
    std::fill(min_time, min_time + MAXN, INF);
    scanf("%d %d %d %d", &c, &n, &s, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &vertex[i]);
        vertex[i] -= c / 2;  // to make code easier
    }
    for (int i = 0; i < m; i++)
    {
        int c1, c2, t;
        scanf("%d %d %d", &c1, &c2, &t);
        edge[c1][c2] = edge[c2][c1] = t;
    }
    dijkstra();
    dfs(s);
    printf("%d 0", min_bring);
    for (int i = min_path.size() - 1; i >= 0; i--)
        printf("->%d", min_path[i]);
    printf(" %d", min_fetch);
    return 0;
}