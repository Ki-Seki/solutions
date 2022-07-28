#include <stdio.h>
#include <stdbool.h>
#define MAXN 5005
#define MAXSET 100000005
int offset[MAXN] = {0}, n, h, m, a, b, tmp;
bool set[MAXSET] = {false};

int main()
{
    scanf("%d %d %d", &n, &h, &m);
    while (m--)
    {
        scanf("%d %d", &a, &b);
        // ensure a < b
        if (a > b)
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        // ensure not duplicate
        if (set[a * 10000 + b] == 0)
            set[a * 10000 + b] = 1;
        else
            continue;
        // calculate
        for (int i = a + 1; i < b; i++)
            offset[i]--;
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", h + offset[i]);
    return 0;
}