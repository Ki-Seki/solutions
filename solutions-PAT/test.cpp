#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#define MAXN 205
#define INF 0x3fffffff
#define DES "ROM"

using namespace std;

int n, k;
map<string, int> city2code;
map<int, string> code2city;

int vertex[MAXN];
int graph[MAXN][MAXN];
bool is_visited[MAXN] = {};

int pre[MAXN], min_cost[MAXN], number[MAXN] = {}, citys[MAXN] = {}, happiness[MAXN] = {}, avg_happiness[MAXN] = {};

// start from 0
void dijkstra()
{
    // init
    fill(min_cost, min_cost + MAXN, INF);
    pre[0] = 0;
    min_cost[0] = 0;
    number[0] = 1;
    // n loops
    for (int i = 0; i < n; i++)
    {
        // find u
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (is_visited[j] == false && min_cost[j] < min)
            {
                u = j;
                min = min_cost[j];
            }
        // end
        if (u == -1 || u == city2code[DES]) break;
        // visit
        is_visited[u] = true;
        //update
        for (int j = 0; j < n; j++)
            // 以下的更新逻辑是要重点掌握的
            if (is_visited[j] == false && graph[u][j] < INF)
                if (min_cost[u] + graph[u][j] < min_cost[j])  // 第一标尺
                {
                    pre[j] = u;
                    min_cost[j] = min_cost[u] + graph[u][j];
                    number[j] = number[u];
                    citys[j] = citys[u] + 1;
                    happiness[j] = happiness[u] + vertex[j];
                    avg_happiness[j] = happiness[j] / citys[j];
                }
                else if (min_cost[u] + graph[u][j] == min_cost[j])
                {
                    number[j] += number[u];
                    if (happiness[u] + vertex[j] > happiness[j])  // 第二标尺
                    {
                        pre[j] = u;
                        citys[j] = citys[u] + 1;
                        happiness[j] = happiness[u] + vertex[j];
                        avg_happiness[j] = happiness[j] / citys[j];
                    }
                    else if (happiness[u] + vertex[j] == happiness[j]
                             && citys[u] + 1 < citys[j])  // 第三标尺
                    {
                        citys[j] = citys[u] + 1;
                        avg_happiness[j] = happiness[j] / citys[j];
                    }
                }
    }
}

void print_path(int des)
{
    if (des == pre[des]) return;
    print_path(pre[des]);
    printf("%s->", code2city[pre[des]].c_str());
}

int main()
{
    fill(graph[0], graph[0] + MAXN * MAXN, INF);
    cin >> n >> k >> code2city[0];
    city2code[code2city[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> code2city[i] >> vertex[i];
        city2code[code2city[i]] = i;
    }
    for (int i = 0; i < k; i++)
    {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        graph[city2code[city1]][city2code[city2]] = graph[city2code[city2]][city2code[city1]] = cost;
    }
    dijkstra();
    int des = city2code[DES];
    printf("%d %d %d %d\n", number[des], min_cost[des], happiness[des], avg_happiness[des]);
    print_path(des);
    printf("%s", DES);
    return 0;
}