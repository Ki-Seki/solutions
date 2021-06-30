/*
 * hint:
 * 本题使用两种方法：
 * 1. Prim
 * 2. Kruskal
*/

// // method 1: Prim
// #include <cstdio>
// #include <vector>
// #include <cstring>
// #define MAXV 102
// #define INF 0x3fffffff

// using namespace std;

// struct Node {
//     int v, dist;
// };

// int n;
// vector<Node> adj[MAXV];
// bool is_visited[MAXV];

// int dist[MAXV];

// void init()
// {
//     for (int i = 0; i < MAXV; i++)
//         adj[i].clear();
//     memset(is_visited, false, sizeof(is_visited));
//     fill(dist, dist + MAXV, INF);
// }

// int prim(int s)
// {
//     // step 0: initialize
//     int ans = 0;
//     dist[s] = 0;
//     // n times traversal
//     for (int i = 0; i < n; i++)
//     {
//         // step 1: find unvisted u with minimum dist[]
//         int u = -1, min = INF;
//         for (int i = 1; i <= n; i++)
//             if (is_visited[i] == false && dist[i] < min)
//             {
//                 u = i;
//                 min = dist[i];
//             }
//         if (u == -1) break;
//         is_visited[u] = true;
//         ans += dist[u];

//         // step 2: update neighbors of u
//         for (int i = 0; i < adj[u].size(); i++)
//         {
//             int v = adj[u][i].v, d = adj[u][i].dist;
//             if (is_visited[v] == false && d < dist[v])
//                 dist[v] = d;  // relaxation
//         }
//     }
//     return ans;
// }

// int main()
// {
//     while (scanf("%d", &n) != EOF && n != 0)
//     {
//         init();
//         int c1, c2, d;
//         for (int i = 0; i < n * (n - 1) / 2; i++)
//         {
//             scanf("%d %d %d", &c1, &c2, &d);
//             adj[c1].push_back({c2, d});
//             adj[c2].push_back({c1, d});
//         }
//         printf("%d\n", prim(1));
//     }
//     return 0;
// }

// method 2: Kruskal
#include <cstdio>
#include <algorithm>
#define MAXV 102
#define MAXE 5000

using namespace std;

struct Edge {
    int u, v;
    int weight;
};

int nv, ne;
int set[MAXV];  // a union-find set, store all vertexes
Edge edges[MAXE];  // store all edges

void init()
{
    ne = nv * (nv - 1) / 2;
    for (int i = 0; i < MAXV; i++)
        set[i] = i;
}

bool cmp(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

int find(int x)
{
    if (set[x] == x)
        return x;
    else
    {
        int root = find(set[x]);
        set[x] = root;
        return root;
    }
}

int kruskal()
{
    // step 0: initialize
    int ans = 0, cnt_edge = 0;
    sort(edges, edges + ne, cmp);

    // step 1: traverse all edges
    for (int i = 0; i < ne; i++)
    {
        int root_u = find(edges[i].u), root_v = find(edges[i].v);
        if (root_u != root_v)
        {
            set[root_u] = root_v;
            ans += edges[i].weight;
            cnt_edge++;
            if (cnt_edge == nv - 1) break;
        }
    }
    if (cnt_edge == nv - 1) return ans;
    else return -1;
}

int main()
{
    while (scanf("%d", &nv) != EOF && nv != 0)
    {
        init();
        int c1, c2, d;
        for (int i = 0; i < ne; i++)
        {
            scanf("%d %d %d", &c1, &c2, &d);
            edges[i] = {c1, c2, d};
        }
        printf("%d\n", kruskal());
    }
    return 0;
}