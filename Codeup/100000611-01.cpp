#include <cstdio>

int dfs(int m, int n)
{
    if (m == 1) return n;  // 破解数据为“1 1000000000”的情况
    if (m > n) return 0;
    return 1 + dfs(2 * m, n) + dfs(2 * m + 1, n);
}

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) == 2 && m != 0 && n != 0)
        printf("%d\n", dfs(m, n));
    return 0;
}