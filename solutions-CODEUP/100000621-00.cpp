#include <cstdio>
#include <algorithm>
#define MAXN 55
#define INF 0x3fffffff

int n, s;

int graph[MAXN][MAXN];
bool is_visited[MAXN] = {};

int distance[MAXN];  // minimum distance from s to i

void dijkstra(int s)
{
    // init
    distance[s] = 0;

    // n loops
    for (int i = 0; i < n; i++)
    {
        // find u
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (distance[j] < min && is_visited[j] == false)
            {
                u = j;
                min = distance[j];
            }
        // end
        if (u == -1) break;
        // mark u as visited
        is_visited[u] = true;
        // update u's neighbors
        for (int j = 0; j < n; j++)
            if (distance[u] + graph[u][j] < distance[j] && is_visited[j] == false)
                    distance[j] = distance[u] + graph[u][j];
    }
}

int main()
{
    // init
    std::fill(graph[0], graph[0] + MAXN * MAXN, INF);
    std::fill(distance, distance + MAXN, INF);

    // input
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &graph[i][j]) && graph[i][j] == 0)
                graph[i][j] = INF;
            
    
    // dijkstra
    dijkstra(s);

    // output
    int not_first_output = 0;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] == INF)
            distance[i] = -1;
        if (i != s)
            printf(not_first_output++ ? " %d" : "%d", distance[i]);
    }
    printf("\n");
    return 0;
}