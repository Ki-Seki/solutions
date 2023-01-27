#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 1005

using namespace std;

int n, l, k;

bool edge[MAXN][MAXN] = {};  // “edge[a][b] = true”：path a -> b exists
int layer[MAXN] = {};  // “layer[v] = x”：the layer of vertex, v is x
int in_queue[MAXN] = {};

int bfs(int id)
{
    int possible_forward = 0;

    queue<int> q;
    q.push(id);
    in_queue[id] = true;

    layer[id] = 0;
    while (q.size())
    {
        int front = q.front(), front_layer = layer[front];
        q.pop();
        if (1 <= front_layer && front_layer <= l)
            possible_forward++;

        for (int i = 1; i <= n; i++)
            if (in_queue[i] == false && edge[front][i] == true)
            {
                q.push(i);
                in_queue[i] = true;
                layer[i] = front_layer + 1;
            }
    }
    return possible_forward;
}

int main()
{
    scanf("%d %d", &n, &l);
    for (int follower = 1; follower <= n; follower++)
    {
        int m, followee;
        scanf("%d", &m);
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &followee);
            edge[followee][follower] = true;
        }
    }
    scanf("%d", &k);
    for (int query = 0; query < k; query++)
    {
        int id;
        scanf("%d", &id);
        printf("%d\n", bfs(id));

        memset(layer, 0, sizeof(layer));
        memset(in_queue, 0, sizeof(in_queue));
    }
    return 0;
}