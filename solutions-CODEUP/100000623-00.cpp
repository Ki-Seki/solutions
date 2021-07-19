/*
 * hint:
 * 本题必须用栈，而不能是队列，不然不能 AC
*/
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define MAXN 55

using namespace std;

int n;
bool graph[MAXN][MAXN];
int in_degree[MAXN];
int ans[MAXN];

bool topological_sort()
{
    // step 0: initialize
    int num = 0;
    stack<int> q;

    // step 1: push vertexes whose in-degrees are 0
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i);
    
    // step 2: bfs
    while (q.size())
    {
        int u = q.top();
        q.pop();
        ans[num++] = u;
        for (int v = 0; v < n; v++)
            if (graph[u][v])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    q.push(v);
            }
    }
    if (num == n) return true;
    else return false;
}

int main()
{
    while (scanf("%d", &n) != EOF && n != 0)
    {
        memset(in_degree, 0, sizeof(in_degree));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == true)
                    in_degree[j]++;
            }
        if (topological_sort())
            for (int i = 0; i < n; i++)
                printf(i == n - 1 ? "%d \n" : "%d ", ans[i]);
        else
            printf("ERROR\n");
    }
    return 0;
}