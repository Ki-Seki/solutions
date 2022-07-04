#include <cstdio>
#define MAXM 45
int ans[MAXM] = {0}, n;

int dfs(int i)
{
    if (ans[i] == 0)
        ans[i] = dfs(i-2) + dfs(i-1);
    return ans[i];
}

int main()
{
    scanf("%d", &n);

    // cal ans
    ans[1] = ans[2] = 1;
    ans[3] = 2;
    dfs(41);

    while (n--)
    {
        int quiz;
        scanf("%d", &quiz);
        printf("%d\n", ans[quiz]);
    }
    return 0;
}