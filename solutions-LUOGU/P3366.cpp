// Kruskal Algorithm
#include <cstdio>
#include <algorithm>
#define MAXM 200005
#define MAXN 5005
using namespace std;

struct Edge {
    int x, y, z;
} Edges[MAXM];
int father[MAXN];  // union-find set
int n, m, ans = 0;

int cmp(Edge &a, Edge &b)
{
    return a.z < b.z;
}

int find(int a)
{
    if (father[a] == a) return a;
    else
    {
        father[a] = find(father[a]);
        return father[a];
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) scanf("%d %d %d", &Edges[i].x, &Edges[i].y, &Edges[i].z);
    sort(Edges+1, Edges+1+m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int u = Edges[i].x, v = Edges[i].y,
            fu = find(u), fv = find(v);
        if (fu != fv)
        {
            father[fu] = fv;
            ans += Edges[i].z;
        }
    }
    bool has_answer = true;
    int f = find(1);
    for (int i = 2; i <= n; i++)
        if (find(i) != f)
        {
            has_answer = false;
            break;
        }
    if (has_answer)
        printf("%d\n", ans);
    else
        printf("orz\n");
    return 0;
}