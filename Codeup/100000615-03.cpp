#include <cstdio>
#include <algorithm>
#define MAXN 10000005

using namespace std;

int set[MAXN],
    cnt[MAXN];  // 记录以 root 为键的朋友簇中的朋友个数

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
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= MAXN; i++)
        {
            set[i] = i;
            cnt[i] = 0;
        }
        int a, b, local_maxn = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            union_sets(a, b);
            if (max(a, b) > local_maxn)
                local_maxn = max(a, b);
        }
        for (int i = 1; i <= local_maxn; i++)
            cnt[find(i)]++;
        int max = 1;
        for (int i = 1; i <= local_maxn; i++)
            if (cnt[i] > max)
                max = cnt[i];
        printf("%d\n", max);
    }
    return 0;
}