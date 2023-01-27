#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 505
#define INF 0x3fffffff

int n, m, s, d;

int distance[MAXN][MAXN];
int cost[MAXN][MAXN];
bool is_visited[MAXN] = {};

int pre[MAXN] = {};
int min_distance[MAXN];
int min_cost[MAXN];

void dijkstra(int s, int d)
{
    pre[s] = s;
    min_distance[s] = 0;
    min_cost[s] = 0;
    for (int i = 0; i < n; i++)
    {
        // find a minimum unvisited node, u
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (min_distance[j] < min && is_visited[j] == false)
            {
                u = j;
                min = distance[s][j];
            }
        // prune
        if (u == -1 || u == d) return;
        // mark u as visited
        is_visited[u] = true;
        // update u's neighbors
        for (int j = 0; j < n; j++)
            if (distance[u][j] < INF && is_visited[j] == false)
            {
                if (min_distance[u] + distance[u][j] < min_distance[j])
                {
                    pre[j] = u;
                    min_cost[j] = min_cost[u] + cost[u][j];
                    min_distance[j] = min_distance[u] + distance[u][j];
                }
                else if (min_distance[u] + distance[u][j] == min_distance[j])
                    if (min_cost[u] + cost[u][j] < min_cost[j])
                    {
                        pre[j] = u;
                        min_cost[j] = min_cost[u] + cost[u][j];
                    }
            }
    }
}

void dfs(int d)
{
    if (pre[d] == d)
    {
        printf("%d ", d);
        return;
    }
    dfs(pre[d]);
    printf("%d ", d);
}

int main()
{
    // init
    std::fill(distance[0], distance[0] + MAXN * MAXN, INF);
    std::fill(cost[0], cost[0], INF);
    std::fill(min_distance, min_distance + MAXN, INF);
    std::fill(min_cost, min_cost + MAXN, INF);

    // input
    scanf("%d %d %d %d", &n, &m, &s, &d);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, dis, cos;
        scanf("%d %d %d %d", &c1, &c2, &dis, &cos);
        distance[c1][c2] = distance[c2][c1] = dis;
        cost[c1][c2] = cost[c2][c1] = cos;
    }
    dijkstra(s, d);
    dfs(d);  // to output the path
    printf("%d %d", min_distance[d], min_cost[d]);
    return 0;
}