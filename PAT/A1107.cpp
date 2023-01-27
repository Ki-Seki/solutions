#include <cstdio>
#include <algorithm>
#define MAXN 1005

using namespace std;

int set[MAXN],  // 兴趣的并查集
    hobby[MAXN],  // 某个人的第一个兴趣，即映射：某个人的编号 -> 某个人的第一个的兴趣
    ans[MAXN] = {};  // 表明某个兴趣簇的 root 的出现次数

void init()
{
    for (int i = 0; i < MAXN; i++)
        set[i] = i;
}

int find(int x)
{
    if (x == set[x])
        return x;
    else
    {
        int root = find(set[x]);
        set[x] = root;
        return root;
    }
    
}

void union_sets(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a != root_b)
        set[root_a] = root_b;
}

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    init();
    int n, k, h1, h;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d: %d", &k, &h1);
        for (int j = 1; j < k; j++)
        {
            scanf("%d", &h);
            union_sets(h1, h);  // 构造兴趣簇
        }
        
        hobby[i] = h1;  // 记录第 i 个人的第一个兴趣
    }
    for (int i = 1; i <= n; i++)
        ans[find(hobby[i])]++;
    sort(ans, ans + MAXN, cmp);
    int pos = 0;
    while (ans[pos] != 0)
        pos++;
    printf("%d\n", pos);
    for (int i = 0; i < pos; i++)
        printf(i == pos - 1 ? "%d" : "%d ", ans[i]);
    return 0;
}