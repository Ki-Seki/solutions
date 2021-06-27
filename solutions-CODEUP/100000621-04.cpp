/*
 * hint:
 * 本题使用以下方法：
 * 1. Bellman-Ford Algorithm
 * 2. SPFA
 * 3. DFS
*/

// // method 1: Bellman-Ford Algorithm
// #include <cstdio>
// #include <vector>
// #define MAXV 1005
// #define INF 0x3fffffff

// using namespace std;

// struct Node {
//     int v, dist, cost;
// };

// int n, m, s, t;

// vector<Node> adj[MAXV];
// int dist[MAXV];  // dist[i]: minimum distance from s to i
// int cost[MAXV];  // cost[i]: minimum cost from s to i

// void init()
// {
//     for (int i = 0; i < MAXV; i++)
//         adj[i].clear();
//     fill(dist, dist + MAXV, INF);
//     fill(cost, cost + MAXV, INF);
// }

// bool bellman_ford(int s)
// {
//     // step 1: initialize
//     dist[s] = cost[s] = 0;

//     // step 2: (n-1) times relaxation
//     for (int i = 0; i < n - 1; i++)
//         for (int u = 1; u <= n; u++)
//             for (int j = 0; j < adj[u].size(); j++)
//             {
//                 int v = adj[u][j].v, d = adj[u][j].dist, c = adj[u][j].cost;
//                 if (dist[u] + d < dist[v])
//                 {
//                     dist[v] = dist[u] + d;
//                     cost[v] = cost[u] + c;
//                 }
//                 else if (dist[u] + d == dist[v] && cost[u] + c < cost[v])
//                     cost[v] = cost[u] + c;
//             }

//     // step 3: detect negative cycle
//     for (int u = 1; u <= n; u++)
//         for (int j = 0; j < adj[u].size(); j++)
//         {
//             int v = adj[u][j].v, d = adj[u][j].dist;
//             if (dist[u] + d < dist[v])
//                 return false;
//         }
//     return true;
// }

// int main()
// {
//     while (scanf("%d %d", &n, &m) && n != 0 && m != 0)
//     {
//         init();
//         int a, b, d, p;
//         for (int i = 0; i < m; i++)
//         {
//             scanf("%d %d %d %d", &a, &b, &d, &p);
//             adj[a].push_back({b, d, p});
//             adj[b].push_back({a, d, p});
//         }
//         scanf("%d %d", &s, &t);
//         if (bellman_ford(s))
//             printf("%d %d\n", dist[t], cost[t]);
//         else
//             printf("Detected negative cycle.\n");
//     }
//     return 0;
// }

// method 2: SPFA
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXV 1005
#define INF 0x3fffffff

using namespace std;

struct Node {
    int v, dist, cost;
};

int n, m, s, t;

vector<Node> adj[MAXV];
bool in_queue[MAXV];
int in_queue_times[MAXV];

int dist[MAXV], cost[MAXV];

void init()
{
    for (int i = 0; i < n; i++)
        adj[i].clear();
    memset(in_queue, false, sizeof(in_queue));
    memset(in_queue_times, 0, sizeof(in_queue_times));
    fill(dist, dist + MAXV, INF);
    fill(cost, cost + MAXV, INF);
}

bool spfa(int s)
{
    // initialize
    dist[s] = cost[s] = 0;
    // bfs
    queue<int> q;
    q.push(s);
    in_queue[s] = true;
    in_queue_times[s] = 1;
    while (q.size())
    {
        // pop front;
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        // traverse all edges of u
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v, d = adj[u][i].dist, c = adj[u][i].cost;
            if (dist[u] + d < dist[v])
            {
                dist[v] = dist[u] + d;  // relaxation
                cost[v] = cost[u] + c;
                if (in_queue[v] == false)  // IN-QUEUE PROCEDURE
                {
                    q.push(v);
                    in_queue[v] = true;
                    in_queue_times[v] += 1;
                    if (in_queue_times[v] >= n) return false;
                }
            }
            else if (dist[u] + d == dist[v] && cost[u] + c < cost[v])
                cost[v] = cost[u] + c;
        }
    }
    return true;
}


int main()
{
    while (scanf("%d %d", &n, &m) && n != 0 && m != 0)
    {
        init();
        int a, b, d, p;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d %d", &a, &b, &d, &p);
            adj[a].push_back({b, d, p});
            adj[b].push_back({a, d, p});
        }
        scanf("%d %d", &s, &t);
        if (spfa(s))
            printf("%d %d\n", dist[t], cost[t]);
        else
            printf("Detected negative cycle.\n");
    }
    return 0;
}

// method 3: DFS
