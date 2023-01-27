/*
 * hint:
 * 用 scanf 读取字符时，一定注意误读入 '\n'
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXV 27
#define INF 0x3fffffff

using namespace std;

int n;

struct Edge {
    int u, v;
    int cost;
};

vector<Edge> edges;
int set[MAXV];

bool cmp (Edge a, Edge b)
{
    return a.cost < b.cost;
}

int find(int x)
{
    if (set[x] == x) return x;
    else
    {
        int root = find(set[x]);
        set[x] = root;
        return root;
    }
}

int kruskal()
{
    int ans = 0, cnt_edge = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < edges.size(); i++)
    {
        int root_a = find(edges[i].u), root_b = find(edges[i].v);
        if (root_a != root_b)
        {
            set[root_a] = root_b;
            ans += edges[i].cost;
            cnt_edge++;
            if (cnt_edge == n - 1) break;
        }
    }
    if (cnt_edge == n - 1) return ans;
    else return -1;
}

int main()
{
    while (scanf("%d\n", &n) != EOF && n != 0)
    {
        edges.clear();
        for (int i = 0; i < MAXV; i++) set[i] = i;
        char a, b;
        int k, c;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%c %d\n", &a, &k);
            for (int j = 0; j < k; j++)
            {
                scanf("%c %d\n", &b, &c);
                edges.push_back({a-'A', b-'A', c});
            }
        }
        printf("%d\n", kruskal());
    }
    return 0;
}