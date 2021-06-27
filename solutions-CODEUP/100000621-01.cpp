#include <cstdio>
#define MAXV 55
#define INF 0x3fffffff

int n, dist[MAXV][MAXV];

void floyd()
{
    for (int k = 1; k <= n; k++)  // k is intermediate point
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != 0 && dist[k][j] != 0 && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &dist[i][j]);
            if (dist[i][j] == 0 && i != j)
                dist[i][j] = INF;
        }
    floyd();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", dist[i][j] == INF ? -1 : dist[i][j]);
        printf("\n");
    }
    return 0;
}