/*
 * hint:
 * This problem is solved by two methods:
 * 1. Prim
 * 2. Kruskal
 * 
 * 在使用 Kruskal 方法时，遇到了 debug 很长时间的 runtime error
 * 具体错误见含 BEWARE 的注释行
 * 这个错误导致某种溢出，致使 printf 语句不能够执行，并且无有用的错误提示
 * 此错误来自：如果 j 初始化为 0，则边数将高达 10000 条，其中有一半都是冗余的
*/

// // method 1: Prim, O(V^2) = O(100^2)
// #include <cstdio>
// #include <vector>
// #include <cmath>
// #include <cstring>
// #define MAXV 105
// #define INF __LDBL_MAX__ / 2.0

// using namespace std;

// typedef long double LDBL;
// typedef pair<LDBL, LDBL> Coordinate;

// int n;
// Coordinate vertex[MAXV];
// LDBL graph[MAXV][MAXV];
// bool is_visited[MAXV];
// LDBL dist[MAXV];

// void init()
// {
//     memset(is_visited, false, sizeof(is_visited));
//     fill(dist, dist + MAXV, INF);
// }

// LDBL euclidean_distance(Coordinate a, Coordinate b)
// {
//     LDBL x2 = (a.first - b.first) * (a.first - b.first), y2 = (a.second - b.second) * (a.second - b.second);
//     return sqrt(x2 + y2);
// }

// LDBL prim(int s)
// {
//     // step 0: initialize
//     LDBL ans = 0;
//     dist[s] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // step 1: find unvisited u with minimum dist[]
//         int u = -1;
//         LDBL min = INF;
//         for (int j = 0; j < n; j++)
//             if (is_visited[j] == false && dist[j] < min)
//             {
//                 u = j;
//                 min = dist[j];
//             }
//         if (u == -1) break;
//         is_visited[u] = true;
//         ans += dist[u];
//         // step 2: update u's neighbors
//         for (int v = 0; v < n; v++)
//             if (is_visited[v] == false && graph[u][v] < dist[v])
//                 dist[v] = graph[u][v];  // relaxation
//     }
//     return ans;
// }

// int main()
// {
//     int kase;
//     scanf("%d", &kase);
//     while (kase--)
//     {
//         scanf("%d", &n);
//         init();
//         for (int i = 0; i < n; i++)
//             scanf("%llf %llf", &vertex[i].first, &vertex[i].second);
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 graph[i][j] = graph[j][i] = euclidean_distance(vertex[i], vertex[j]);
//         printf("%.2Lf\n", prim(0));
//         if (kase) printf("\n");  // The outputs of two consecutive cases will be separated by a blank line.
//     }
//     return 0;
// }

// method 2: Kruskal, O(ElogE) = O(5000log5000)
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#define MAXV 105
#define MAXE 5005

using namespace std;

typedef pair<double, double> Coordinate;

struct Edge {
    int u, v;
    double weight;
};

int nv, ne;
Coordinate vertex[MAXV];  // raw data
int set[MAXV];  // union-find set, store vertexes
Edge edges[MAXE];

void init()
{
    for (int i = 0; i < MAXV; i++)
        set[i] = i;
    ne = 0;
}

double euclidean_distance(Coordinate &a, Coordinate &b)
{
    double x2 = (a.first - b.first) * (a.first - b.first), y2 = (a.second - b.second) * (a.second - b.second);
    return sqrt(x2 + y2);
}

bool cmp(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

int find(int x)
{
    int root = x;
    while (root != set[root])
        root = set[root];
    // optimization
    while (x != root)
    {
        int tmp = set[x];
        set[x] = root;
        x = tmp;
    }
    return root;
}

double kruskal()
{
    // step 0: init
    double ans = 0;
    int cnt_edge = 0;
    sort(edges, edges + ne, cmp);
    // step 1: traverse all edges
    for (int i = 0; i < ne; i++)
    {
        int root_a = find(edges[i].u), root_b = find(edges[i].v);
        if (root_a != root_b)
        {
            set[root_a] = root_b;
            ans += edges[i].weight;
            cnt_edge++;
            if (cnt_edge == nv - 1) break;
        }
    }
    if (cnt_edge != nv - 1) return -1;
    else return ans;
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%d", &nv);
        init();
        for (int i = 0; i < nv; i++)
            scanf("%lf %lf", &vertex[i].first, &vertex[i].second);
        for (int i = 0; i < nv; i++)
            for (int j = i + 1; j < nv; j++)  // BEWARE!!!! j must be i + 1 rather than 0
                edges[ne++] = {i, j, euclidean_distance(vertex[i], vertex[j])};
        printf("%.2f\n", kruskal());
        if (kase) printf("\n");  // The outputs of two consecutive cases will be separated by a blank line.
    }
    return 0;
}