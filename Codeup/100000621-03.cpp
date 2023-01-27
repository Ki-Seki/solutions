/*
 * hint:
 * 评测机应该有误，给出以下测试点：
 * 
 * INPUT
5 6 0 2
0 1 1
0 2 2
1 2 1
0 3 1
2 4 1
3 4 1
 * OUTPUT
2
0 2
* 
* 本题使用以下方法解决：
* 1. Bellman-Ford Algorithm
* 2. SPFA
* 
*/

// // Bellman-Ford Algorithm
// #include <cstdio>
// #include <vector>
// #define MAXV 1005
// #define INF 0x3fffffff

// using namespace std;

// struct Node {
//     int v, dist;
// };

// int n, m, s, t;

// vector<Node> adj[MAXV];

// int dist[MAXV];
// int pre[MAXV];

// void init()
// {
//     for (int i = 0; i < MAXV; i++)
//         adj[i].clear();
//     fill(dist, dist + MAXV, INF);
// }

// bool bellman_ford(int s)
// {
//     // step 1: initialize
//     dist[s] = 0;
//     // step 2: (n-1) times relaxation
//     for (int i = 0; i < n - 1; i++)
//         for (int u = 0; u < n; u++)
//             for (int j = 0; j < adj[u].size(); j++)
//             {
//                 int v = adj[u][j].v, d = adj[u][j].dist;
//                 if (dist[u] + d < dist[v])
//                 {
//                     dist[v] = dist[u] + d;
//                     pre[v] = u;
//                 }
//                 else if (dist[u] + d == dist[v] && u < pre[v])
//                     pre[v] = u;
//             }
//     // step 3: detect negative cycle
//     for (int u = 0; u < n; u++)
//         for (int j = 0; j < adj[u].size(); j++)
//             if (dist[u] + adj[u][j].dist < dist[adj[u][j].v])
//                 return false;
//     return true;
// }

// void print_path(int st, int ed)
// {
//     if (ed == st)
//         return;
//     print_path(st, pre[ed]);
//     printf(" %d", ed);
// }

// int main()
// {
//     while (scanf("%d %d %d %d", &n, &m, &s, &t) != EOF)
//     {
//         init();
//         for (int i = 0; i < m; i++)
//         {
//             int c1, c2, d;
//             scanf("%d %d %d", &c1, &c2, &d);
//             adj[c1].push_back({c2, d});
//             adj[c2].push_back({c1, d});
//         }
//         if (bellman_ford(s))
//         {
//             if (dist[t] == INF)
//                 printf("can't arrive\n");
//             else
//             {
//                 printf("%d\n%d", dist[t], s);
//                 print_path(s, t);
//                 printf("\n");
//             }
//         }
//         else
//             printf("Exist negative cycle!\n");
//     }
//     return 0;
// }

// SPFA
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAXV 1005
#define INF 0x3fffffff

using namespace std;

struct Node {
    int v, dist;
};

int n, m, s, t;

vector<Node> adj[MAXV];
bool in_queue[MAXV];
int in_queue_times[MAXV];

int dist[MAXV];
int pre[MAXV];

void init()
{
    for (int i = 0; i < MAXV; i++)
        adj[i].clear();
    fill(dist, dist + MAXV, INF);
    memset(in_queue, false, sizeof(in_queue));
    memset(in_queue_times, 0, sizeof(in_queue_times));
}

bool spfa(int s)
{
    // initialize
    dist[s] = 0;
    // bfs
    queue<int> q;
    q.push(s);
    in_queue[s] = true;
    in_queue_times[s]++;
    while (q.size())
    {
        // pop front, u
        int u = q.front();
        q.pop();
        in_queue[s] = false;
        // traverse all edges of u
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v, d = adj[u][i].dist;
            if (dist[u] + d < dist[v])
            {
                dist[v] = dist[u] + d;
                pre[v] = u;
                if (in_queue[v] == false)
                {
                    q.push(v);
                    in_queue[v] = true;
                    in_queue_times[v]++;
                    if (in_queue_times[v] >= n)
                        return false;
                }
            }
            else if (dist[u] + d == dist[v] && u < pre[v])
                pre[v] = u;
        }
    }
    return true;
}

void print_path(int st, int ed)
{
    if (ed == st)
        return;
    print_path(st, pre[ed]);
    printf(" %d", ed);
}

int main()
{
    while (scanf("%d %d %d %d", &n, &m, &s, &t) != EOF)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int c1, c2, d;
            scanf("%d %d %d", &c1, &c2, &d);
            adj[c1].push_back({c2, d});
            adj[c2].push_back({c1, d});
        }
        if (spfa(s))
        {
            if (dist[t] == INF)
                printf("can't arrive\n");
            else
            {
                printf("%d\n%d", dist[t], s);
                print_path(s, t);
                printf("\n");
            }
        }
        else
            printf("Exist negative cycle!\n");
    }
    return 0;
}