/*
 * hint:
 * 本题使用两种方法，邻接矩阵和邻接表两种
 * 邻接矩阵一直无法 AC，原因尚未找出
 * 
 * 给出两组测试样例
 * 第一组：测试输入超范围数据
3 2
9 5
1 3
0 0
 * 第二组：测试输入重复数据
3 2
0 2
0 2
0 0
 * 
 * 使用邻接表方法时，上述两种输入无需额外处理，因为
 * 当超出范围时，邻接表方法计算出的 num 一定不等于 n，因此顺利返回 NO
 * 当重复输入时，邻接表方法的重复计算恰使结果正确
 * 
 * 使用邻接矩阵时，代码中两行 VITAL 注释标注的行提供了非法数据解决方案
 * 
 * 其他一定尚有未测试出的不一致内容。但是方法二通过了测试并不能说明邻接表法一定是正确的
*/

// // method 1: adjacency matrix
// #include <cstdio>
// #include <queue>
// #include <cstring>
// #include <set>
// #define MAXN 110

// using namespace std;

// int n, m;
// bool graph[MAXN][MAXN];
// int in_degree[MAXN];
// set<pair<int, int>> inputs;

// bool topological_sort()
// {
//     // step 0: initialize
//     int num = 0;
//     queue<int> q;

//     // step 1: push vertexes whose in-degrees are 0
//     for (int i = 0; i < n; i++)
//         if (in_degree[i] == 0)
//             q.push(i);
    
//     // step 2: bfs
//     while (q.size())
//     {
//         int u = q.front();
//         q.pop();
//         num++;
//         for (int v = 0; v < n; v++)
//             if (graph[u][v] == true)
//             {
//                 in_degree[v]--;
//                 if (in_degree[v] == 0)
//                     q.push(v);
//             }
//     }
//     if (num == n) return true;
//     else return false;
// }

// int main()
// {
//     while (scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0)
//     {
//         memset(in_degree, 0, sizeof(in_degree));
//         // memset(graph, false, sizeof(graph));
//         fill(graph[0], graph[0] + MAXN * MAXN, false);
//         bool is_valid = true;
//         for (int i = 0; i < m; i++)
//         {
//             int x, y;
//             scanf("%d %d", &x, &y);
//             if (is_valid && !(0 <= x && x < n && 0 <= y && y < n))  // VITAL. deal with invalid inputs
//                 is_valid = false;
//             if (inputs.count({x, y}) == 0)  // VITAL. deal with duplicated inputs
//             {
//                 inputs.insert({x, y});
//                 graph[x][y] = true;
//                 in_degree[y]++;
//             }
//         }
//         printf(is_valid && topological_sort() ? "YES\n" : "NO\n");
//     }
//     return 0;
// }

// method 2: adjacency list
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 110

using namespace std;

int n, m;
vector<int> adj[MAXN];
int in_degree[MAXN];

bool topological_sort()
{
    // step 0: initialize
    int num = 0;
    queue<int> q;

    // step 1: push vertexes whose in-degrees are 0
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            q.push(i);
    
    // step 2: bfs
    while (q.size())
    {
        int u = q.front();
        q.pop();
        num++;
		for (int i = 0; i < adj[u].size(); i++)
        {
			int v = adj[u][i];
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
    while (scanf("%d %d", &n, &m) != EOF && n != 0 && m != 0)
    {
        memset(in_degree, 0, sizeof(in_degree));
		for (int i = 0; i < MAXN; i++)
			adj[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
			adj[x].push_back(y);
            in_degree[y]++;
        }
        printf(topological_sort() ? "YES\n" : "NO\n");
    }
    return 0;
}