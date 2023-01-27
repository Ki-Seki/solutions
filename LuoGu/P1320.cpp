#include <bits/stdc++.h>
#define MAXN 200
using namespace std;

char han[MAXN * MAXN + 5], tmp;

int main()
{
    int i = 0;
    while (scanf("%c", &tmp) != EOF)
        if (tmp == '0' || tmp == '1')
            han[i++] = tmp;
    int n = sqrt(i);
    printf("%d ", n);
    int acc = 1;
    if (han[0] == '1') printf("0 ");
    char now = han[0];
    for (int j = 1; j < i; j++)
    {
        if (han[j] == now)
            acc++;
        else
        {
            printf("%d ", acc);
            now = han[j];
            acc = 1;
        }
        if (j == i - 1)
            printf("%d", acc);
    }
    return 0;
}