#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 1005

using namespace std;

vector<int> adj_list[MAXN];
bool in_queue[MAXN] = {};

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    in_queue[n] = true;
    while (q.size())
    {
        int front = q.front(); q.pop();
        for (int i = 0; i < adj_list[front].size(); i++)
        {
            int v = adj_list[front][i];
            if (v != 0)
            {
                q.push(v);
                in_queue[v] = true;
                adj_list[front][i] = 0;
            }
        }
    }
}

bool is_connected_graph(int size)
{
    bfs(1);
    for (int i = 1; i <= size; i++)
        if (in_queue[i] == false)
            return false;
    return true;
}

void reset(int size)
{
    for (int i = 1; i <= size; i++)
    {
        adj_list[i].clear();
        in_queue[i] = false;
    }
}

int main()
{
    int n, m;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        scanf("%d", &m);
        int a, b;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        printf(is_connected_graph(n) ? "YES\n" : "NO\n");
        reset(n);
    }
    return 0;
}