#include <iostream>

int cbn(int m, int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = ans * (m - n + i) / i;
    return ans;
}

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
        printf("%d\n", cbn(m, n));
    return 0;
}