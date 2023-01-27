#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 1005

using namespace std;

int n, m, k;

bool edge[MAXN][MAXN] = {};  // adjacency matrix
bool in_queue[MAXN] = {};

void bfs(int city, int city_concern)
{
    queue<int> q;
    q.push(city);
    in_queue[city] = true;
    while (q.size())
    {
        int front = q.front(); q.pop();
        for (int i = 1; i <= n; i++)
            if (i != city_concern && in_queue[i] == false && edge[front][i] == true)
            {
                q.push(i);
                in_queue[i] = true;
            }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int city1, city2;
        scanf("%d %d", &city1, &city2);
        edge[city1][city2] = edge[city2][city1] = true;
    }
    for (int i = 0; i < k; i++)
    {
        memset(in_queue, false, sizeof(in_queue));
        int city_concern, component = 0;
        scanf("%d", &city_concern);
        for (int city = 1; city <= n; city++)  // traverse all citys
            if (city != city_concern && in_queue[city] == false)
            {
                bfs(city, city_concern);
                component++;
            }
        printf("%d\n", component == 0 ? 0 : component - 1);
    }
    return 0;
}