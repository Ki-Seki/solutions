#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXV 1015
#define INF 0x3fffffff

int n, m, k, ds;

int graph[MAXV][MAXV];
bool is_visited[MAXV];

int dist[MAXV];
int best_station = -1, min_dist = -1, tot_dist = INF;

// for a house, just return origin id;
// for a station, return (n + origin id)
int get_id(char name[])
{
    int len = strlen(name), id = 0;
    if (name[0] == 'G')
    {
        name++;
        len--;
        id += n;
    }
    for (int i = len - 1, weight = 1; i >= 0; i--, weight *= 10)
        id += (name[i] - '0') * weight;
    return id;
}

void dijkstra(int s)
{
    // init
    std::fill(is_visited, is_visited + MAXV, false);
    std::fill(dist, dist + MAXV, INF);
    dist[s] = 0;
    // (n + m) loops
    for (int i = 1; i <= n + m; i++)
    {
        // find unvisited u with min dist between u and s
        int u = -1, min = INF;
        for (int j = 1; j <= n + m; j++)
            if (dist[j] < min && is_visited[j] == false)
            {
                u = j;
                min = dist[j];
            }
        // end
        if (u == -1) break;
        // mark u as visited
        is_visited[u] = true;
        // update u's neighbors
        for (int j = 1; j <= n + m; j++)
            if (dist[u] + graph[u][j] < dist[j] && is_visited[j] == false)
                dist[j] = dist[u] + graph[u][j];
    }
    // addition process to get ans
    int tmp_min_dist = INF, tmp_tot_dist = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > ds) return;
        if (dist[i] < tmp_min_dist) tmp_min_dist = dist[i];
        tmp_tot_dist += dist[i];
    }
    if (tmp_min_dist > min_dist ||
        tmp_min_dist == min_dist && tmp_tot_dist < tot_dist)
    {
        best_station = s;
        min_dist = tmp_min_dist;
        tot_dist = tmp_tot_dist;
    }
}

int main()
{
    std::fill(graph[0], graph[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    for (int i = 0; i < k; i++)
    {
        char p1[5], p2[5];
        scanf("%s %s", p1, p2);
        int p1_id = get_id(p1), p2_id = get_id(p2), dist;
        scanf("%d", &dist);
        graph[p1_id][p2_id] = graph[p2_id][p1_id] = dist;
    }
    for (int i = n + 1; i <= n + m; i++)
        dijkstra(i);
    if (best_station == -1)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f", best_station - n, min_dist * 1.0, int(10.0 * tot_dist / n + 0.5) / 10.0);
    return 0;
}