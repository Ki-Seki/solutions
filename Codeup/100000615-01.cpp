#include <cstdio>
#define MAXN 1005

int set[MAXN],  // 并查集
    n, m;
bool flag[MAXN] = {};  // 如果出现某个元素簇的 root，则令 flag[root] = true;

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

void union_sets(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a != root_b)
        set[root_a] = set[root_b];
}

void init(int n)
{
    for (int i = 0; i <= n; i++)
        set[i] = i;
    for (int i = 0; i <= n; i++)
        flag[i] = false;
}

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0) break;
        scanf("%d", &m);

        // 初始化
        init(n);

        // 输入及建树
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            union_sets(a, b);
        }

        // 标记簇的 root
        for (int i = 1; i <= n; i++)
            flag[find(i)] = true;
        
        // 计算簇的个数
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (flag[i])
                cnt++;

        // 输出
        printf("%d\n", cnt - 1);
    }
    return 0;
}