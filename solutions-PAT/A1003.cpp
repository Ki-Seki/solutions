#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 505
#define INF 0x3fffffff

int n, m, start, end;
int team[MAXN];

int graph[MAXN][MAXN];
bool is_visited[MAXN] = {};

int distance[MAXN], shortest_cnt[MAXN], max_members[MAXN];

void dijkstra(int s, int e)
{
    // 初始化
    std::fill(distance, distance + MAXN, INF);
    memset(shortest_cnt, 0, sizeof(shortest_cnt));
    memset(max_members, 0, sizeof(max_members));
    distance[s] = 0;
    shortest_cnt[s] = 1;
    max_members[s] = team[s];
    for (int i = 0; i < n; i++)
    {
        // 找到最小未访问顶点 u，并访问
        int u = -1, min_weight = INF;
        for (int j = 0; j < n; j++)
            if (is_visited[j] == false && distance[j] < min_weight)
            {
                u = j;
                min_weight = distance[j];
            }

        // 剪枝
        // 当 u 已是终点，意味着可以提前结束；
        // 当 u 未找到，意味着已无与 start 连通的节点
        if (u == -1 || u == end) break;

        is_visited[u] = true;
        // 更新 u 的邻居
        for (int j = 0; j < n; j++)
        {
            if (is_visited[j] == false && graph[u][j] < INF)  // 节点未访问 && 边存在
            {
                if (distance[u] + graph[u][j] < distance[j])  // 有更短路径
                {
                    distance[j] = distance[u] + graph[u][j];  // 更新距离
                    shortest_cnt[j] = shortest_cnt[u];  // 更新路径数，继承自 u
                    max_members[j] = max_members[u] + team[j];  // 更新最大点权和
                }
                else if (distance[u] + graph[u][j] == distance[j])  // 有相等路径
                {
                    // 无需更新距离
                    shortest_cnt[j] += shortest_cnt[u];  // 更新路径数，部分继承 u
                    if (max_members[u] + team[j] > max_members[j])  // 更新最大点权和
                        max_members[j] = max_members[u] + team[j];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &start, &end);
    for (int i = 0; i < n; i++)
        scanf("%d", &team[i]);

    // 不能改用 memset，因其是按字节赋值的
    // 不能改成 graph，因为二维数组名 + 1 表示偏移的 size 是一个一维数组的长度
    std::fill(graph[0], graph[0] + MAXN * MAXN, INF);

    for (int i = 0; i < m; i++)
    {
        int c1, c2, l;
        scanf("%d %d %d", &c1, &c2, &l);
        graph[c1][c2] = graph[c2][c1] = l;
    }
    dijkstra(start, end);
    printf("%d %d\n", shortest_cnt[end], max_members[end]);
    return 0;
}