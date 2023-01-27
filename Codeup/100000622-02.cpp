#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXV 105
#define INF 0x3fffffff

using namespace std;

int n, m;
int graph[MAXV][MAXV];
bool is_visited[MAXV];
int cost[MAXV];

int prim(int s)
{
    int ans = 0, cnt_vertex = 0;
    cost[s] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = -1, min = INF;
        for (int j = 1; j <= m; j++)
            if (is_visited[j] == false && cost[j] < min)
            {
                u = j;
                min = cost[j];
            }
        if (u == -1) break;
        ans += cost[u];
        cnt_vertex++;
        is_visited[u] = true;
        for (int v = 1; v <= m; v++)
            if (is_visited[v] == false && graph[u][v] < cost[v])
                cost[v] = graph[u][v];
    }
    if (cnt_vertex == m) return ans;
    else return -1;
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF && n != 0)
    {
        memset(is_visited, false, sizeof(is_visited));
        fill(cost, cost + MAXV, INF);
        fill(graph[0], graph[0] + MAXV * MAXV, INF);
        for (int i = 0; i < n; i++)
        {
            int c1, c2, cost;
            scanf("%d %d %d", &c1, &c2, &cost);
            graph[c1][c2] = graph[c2][c1] = cost;
        }
        int ans = prim(1);
        if (ans == -1)
            printf("?\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}