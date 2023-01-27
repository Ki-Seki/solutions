/*
 * hint:
 * This problem is solved by those methods:
 * 1. Dijkstra's Algorithm      O(V^2 + E)
 * 2. Bellman-Ford Algorithm    O(VE)
 * 3. SPFA                      O(kE)
*/

// // method 1: Dijkstra's Algorithm
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #define MAXN 505
// #define INF 0x3fffffff

// int n, m, start, end;
// int team[MAXN];

// int graph[MAXN][MAXN];
// bool is_visited[MAXN] = {};

// int distance[MAXN], shortest_cnt[MAXN], max_members[MAXN];

// void dijkstra(int s, int e)
// {
//     // 初始化
//     std::fill(distance, distance + MAXN, INF);
//     memset(shortest_cnt, 0, sizeof(shortest_cnt));
//     memset(max_members, 0, sizeof(max_members));
//     distance[s] = 0;
//     shortest_cnt[s] = 1;
//     max_members[s] = team[s];
//     for (int i = 0; i < n; i++)
//     {
//         // 找到最小未访问顶点 u，并访问
//         int u = -1, min_weight = INF;
//         for (int j = 0; j < n; j++)
//             if (is_visited[j] == false && distance[j] < min_weight)
//             {
//                 u = j;
//                 min_weight = distance[j];
//             }

//         // 剪枝
//         // 当 u 已是终点，意味着可以提前结束；
//         // 当 u 未找到，意味着已无与 start 连通的节点
//         if (u == -1 || u == end) break;

//         is_visited[u] = true;
//         // 更新 u 的邻居
//         for (int j = 0; j < n; j++)
//         {
//             if (is_visited[j] == false && graph[u][j] < INF)  // 节点未访问 && 边存在
//             {
//                 if (distance[u] + graph[u][j] < distance[j])  // 有更短路径
//                 {
//                     distance[j] = distance[u] + graph[u][j];  // 更新距离
//                     shortest_cnt[j] = shortest_cnt[u];  // 更新路径数，继承自 u
//                     max_members[j] = max_members[u] + team[j];  // 更新最大点权和
//                 }
//                 else if (distance[u] + graph[u][j] == distance[j])  // 有相等路径
//                 {
//                     // 无需更新距离
//                     shortest_cnt[j] += shortest_cnt[u];  // 更新路径数，部分继承 u
//                     if (max_members[u] + team[j] > max_members[j])  // 更新最大点权和
//                         max_members[j] = max_members[u] + team[j];
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     scanf("%d %d %d %d", &n, &m, &start, &end);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &team[i]);

//     // 不能改用 memset，因其是按字节赋值的
//     // 不能改成 graph，因为二维数组名 + 1 表示偏移的 size 是一个一维数组的长度
//     std::fill(graph[0], graph[0] + MAXN * MAXN, INF);

//     for (int i = 0; i < m; i++)
//     {
//         int c1, c2, l;
//         scanf("%d %d %d", &c1, &c2, &l);
//         graph[c1][c2] = graph[c2][c1] = l;
//     }
//     dijkstra(start, end);
//     printf("%d %d\n", shortest_cnt[end], max_members[end]);
//     return 0;
// }

// // method 2: Bellman-Ford Algorithm
// #include <cstdio>
// #include <vector>
// #include <set>
// #define MAXV 505
// #define INF 0x3fffffff

// using namespace std;

// struct Node {
//     int v, dist;
// };

// int n, m, c1, c2;

// vector<Node> adj[MAXV];
// int weight[MAXV];
// bool is_visited[MAXV] = {};

// int dist[MAXV];
// int num[MAXV] = {};
// int teams[MAXV] = {};
// set<int> pre[MAXV];

// bool bellman_ford(int s)
// {
//     // step 1: initialize
//     fill(dist, dist + MAXV, INF);
//     // num[] has already been initialized
//     dist[s] = 0;
//     num[s] = 1;
//     teams[s] = weight[s];

//     // step 2: (n - 1) times relaxation
//     for (int i = 0; i < n - 1; i++)
//         for (int u = 0; u < n; u++)
//             for (int j = 0; j < adj[u].size(); j++)
//             {
//                 int v = adj[u][j].v, d = adj[u][j].dist;
//                 if (dist[u] + d < dist[v])
//                 {
//                     dist[v] = dist[u] + d;  // relaxation
//                     num[v] = num[u];
//                     teams[v] = teams[u] + weight[v];
//                     pre[v].clear();
//                     pre[v].insert(u);
//                 }
//                 else if (dist[u] + d == dist[v])
//                 {
//                     pre[v].insert(u);
//                     // recompute num[v]
//                     num[v] = 0;
//                     for (set<int>::iterator p = pre[v].begin(); p != pre[v].end(); p++)
//                         num[v] += num[*p];
//                     if (teams[u] + weight[v] > teams[v])
//                         teams[v] = teams[u] + weight[v];
//                 }
//             }
//     // step 3: detect negative cycle
//     // It is guaranteed that there will be no negative weight edge in this problem.
//     return true;
// }

// int main()
// {
//     scanf("%d %d %d %d", &n, &m, &c1, &c2);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &weight[i]);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b, c;
//         scanf("%d %d %d", &a, &b, &c);
//         adj[a].push_back({b, c});
//         adj[b].push_back({a, c});
//     }
//     bellman_ford(c1);
//     printf("%d %d", num[c2], teams[c2]);
//     return 0;
// }

// method 3: SPFA
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#define MAXV 505
#define INF 0x3fffffff

using namespace std;

struct Node {
    int v, dist;
};

int n, m, c1, c2;

vector<Node> adj[MAXV];
int weight[MAXV];
bool in_queue[MAXV] = {};

int dist[MAXV];
int num[MAXV] = {};  // the number of shortest-path
int teams[MAXV] = {};
set<int> pre[MAXV];

bool spfa(int s)
{
    // initialize
    fill(dist, dist + MAXV, INF);
    dist[s] = 0;
    num[s] = 1;
    teams[s] = weight[s];

    queue<int> q;
    q.push(s);
    in_queue[s] = true;
    while (q.size())
    {
        // step 1: pop front
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        // step 2: traverse all edges of u
        for (int j = 0; j < adj[u].size(); j++)
        {
            int v = adj[u][j].v, d = adj[u][j].dist;
            if (dist[u] + d < dist[v])
            {
                dist[v] = dist[u] + d;
                if (in_queue[v] == false)
                {
                    q.push(v);
                    in_queue[v] = true;
                    // guaranteed there is no negative cycle, 
                    // no need to calculate the times of relaxation
                }
                num[v] = num[u];
                teams[v] = teams[u] + weight[v];
                pre[v].clear();
                pre[v].insert(u);
            }
            else if (dist[u] + d == dist[v])
            {
                pre[v].insert(u);
                // recompute num[v]
                num[v] = 0;
                for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++)
                    num[v] += num[*it];
                if (teams[u] + weight[v] > teams[v])
                    teams[v] = teams[u] + weight[v];
                if (in_queue[v] == false)
                // ATTENTION!!!: where there will be change in num[], dist[], etc., there should be an in-queue procedure
                {
                    q.push(v);
                    in_queue[v] = true;
                    // guaranteed there is no negative cycle, 
                    // no need to calculate the times of relaxation
                }
            }
        }
    }
    return true;
    // guaranteed there is no negative cycle, directly return true
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    spfa(c1);
    printf("%d %d", num[c2], teams[c2]);
    return 0;
}