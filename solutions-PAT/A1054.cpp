#include <iostream>
#define MAXN 16777216

int color_time[MAXN + 1] = {};

int main()
{
    int n, m, color, ans = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &color);
            color_time[color]++;
        }
    }
    for (int i = 0; i < MAXN + 1; i++)
        if (color_time[i] > color_time[ans])
            ans = i;
    printf("%d", ans);
    return 0;
}