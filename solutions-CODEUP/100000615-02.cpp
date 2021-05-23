#include <cstdio>
#define MAXN 1005

int set[MAXN];
bool flag[MAXN];  // 标记某个朋友簇的 root 是否出现过

int find(int x)
{
    if (x == set[x])
        return x;
    else
        return set[x] = find(set[x]);
}

void union_sets(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a != root_b)
        set[root_a] = root_b;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int kase = 0; kase < t; kase++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            set[i] = i;
            flag[i] = false;
        }
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            union_sets(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            flag[find(i)] = true;
        for (int i = 1; i <= n; i++)
            if (flag[i])
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}