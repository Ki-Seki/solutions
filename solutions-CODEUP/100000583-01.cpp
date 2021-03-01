#include <iostream>
#define MAXN 25
using namespace std;

int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 1; j <= m; j++)
        {
            int doubleSpace = m - j, cnt = j * 2 - 1;
            for (int k = 0; k < doubleSpace; k++)
                printf("  ");
            for (int k = 0; k < cnt; k++)
                printf(k == cnt -1 ? "%d\n" : "%d ", fib[k]);
        }
    }
    return 0;
}