/*
 * hint:
 * 此题解是在 100000622-02 题的题解基础上做以下修改得到的：
 * 为 Edge 结构体增加 status 属性，排序时增加 status 作为第一标尺，累计边权和时检查其 status
 * 所有增加及修改均用注释“// ANCHOR”标明
 * 
 * 当然也有另外一种更简便的方法，
 * 在输入时，判断如果修建状态为已修建好，则将边权置为 0。如此即可。
*/
#include <cstdio>
#include <algorithm>
#define MAXV 102
#define MAXE 5000

using namespace std;

struct Edge {
    int u, v;
    int weight;
    int status;  // ANCHOR
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
    if (a.status != b.status) return a.status > b.status;  // ANCHOR
    else return a.weight < b.weight;  // ANCHOR
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
            if (edges[i].status == 0)  // ANCHOR
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
        int c1, c2, d, s;
        for (int i = 0; i < ne; i++)
        {
            scanf("%d %d %d %d", &c1, &c2, &d, &s);  // ANCHOR
            edges[i] = {c1, c2, d, s};  // ANCHOR
        }
        printf("%d\n", kruskal());
    }
    return 0;
}