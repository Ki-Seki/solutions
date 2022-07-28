#include <stdio.h>
#define MAXN 100005
int father[MAXN], n, m, op, u, v;

int find(int x)
{
    if (father[x] == x) return x;
    else
    {
        father[x] = find(father[x]);
        return father[x];
    }
}

void union_sets(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) father[fx] = fy;
}

int main()
{
    
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    while (m--)
    {
        scanf("%d %d %d", &op, &u, &v);
        if (op == 1) union_sets(u, v);
        if (op == 2)
        {
            if (find(u) == find(v)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}