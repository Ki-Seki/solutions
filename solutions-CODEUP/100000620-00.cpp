/*
 * hint：
 * 数据量可能非常大，所以不能用 set 来存储节点
*/
#include <cstdio>
#include <vector>
#define MAXN 1000010

using namespace std;

vector<int> adj_list[MAXN];
bool is_visited[MAXN] = {};
bool is_vertex[MAXN] = {};  // 不能改用 set

void dfs(int n)
{
    is_visited[n] = true;
    for (int i = 0; i < adj_list[n].size(); i++)
        if (!is_visited[adj_list[n][i]])
            dfs(adj_list[n][i]);
}

int graph_traversal()
{
    int ans = 0;
    for (int i = 0; i < MAXN; i++)
        if (is_vertex[i] && !is_visited[i])
        {
            ans++;
            dfs(i);
        }
    return ans;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        is_vertex[a] = is_vertex[b] = true;
    }
    printf("%d\n", graph_traversal());
    return 0;
}