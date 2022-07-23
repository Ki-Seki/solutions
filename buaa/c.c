#include <stdio.h>
#define MAXN 1000005
int n, data[MAXN], tmp, ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if (data[tmp] == 0)
            data[tmp] = i;
    }
    while (scanf("%d", &tmp) != EOF)
    {
        ans = data[tmp];
        if (ans) printf("%d\n", ans);
        else printf("NO\n");
    }
    return 0;
}