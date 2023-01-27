#include <cstdio>
#define MAX 10000
#define MAXN 100

bool num[MAX+5] = {0};
int n, all[MAXN+5], ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &all[i]);
        num[all[i]] = true;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (all[i] + all[j] <= MAX && num[all[i]+all[j]] == true)
            {
                ans++;
                num[all[i]+all[j]] = false;
            }
    printf("%d\n", ans);
    return 0;
}