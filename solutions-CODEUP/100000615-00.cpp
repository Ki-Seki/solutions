#include <cstdio>
#define MAXN 1005

int set[MAXN],  // 并查集
    n, m;
bool flag = true;  // true：无重复加入的电缆

int find(int x)
{
    if (x == set[x])
        return x;
    
    // find root
    int root = x;
    while (root != set[root])
        root = set[root];
    
    // optimize
    int index = x;
    while (index != set[index])
    {
        int temp = index;
        set[temp] = root;
        index = set[index];
    }
    return root;
}

void union_set(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a != root_b)
        set[root_a] = set[root_b];
    else
        flag = false;
}

void init(int n)
{
    for (int i = 0; i <= n; i++)
        set[i] = i;
}

bool is_ok(int n)
{
    int root = find(1);
    for (int i = 2; i <= n; i++)
        if (root != find(i))
            return false;
    return true;
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && !(n == 0 && m == 0))
    {
        init(n);
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            union_set(a, b);
        }
        printf(is_ok(n) && flag ? "Yes\n" : "No\n");
    }
    return 0;
}