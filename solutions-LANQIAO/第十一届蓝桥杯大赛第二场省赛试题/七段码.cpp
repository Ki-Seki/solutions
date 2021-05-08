#include<cstdio>
#include<vector>
#include<set>
#define N 7

using namespace std;

vector<int> graph[N + 1];
set<set<int> > characters;
set<int> c;

void add(int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

// index: 已考察过 index 号节点
// now_cnt:已选了 now_cnt 个节点
// limit: 可选节点数
void dfs(int index, int now_cnt, int limit)
{
    // 递归边界
    if (now_cnt == limit)
    {
        if (characters.count(c) == 0)
            characters.insert(c);
        return;
    }

    // 循环分岔口
    for (int i = 0; i < graph[index].size(); i++)
    {
        if (c.count(graph[index][i]) == 0)
        {
            c.insert(graph[index][i]);
            dfs(graph[index][i], now_cnt + 1, limit);
            c.erase(graph[index][i]);
        }
    }
}

int main()
{
    // init
    add(1, 2);
    add(2, 3);
    add(3, 4);
    add(4, 5);
    add(5, 6);
    add(6, 1);
    add(7, 2);
    add(7, 3);
    add(7, 5);
    add(7, 6);

    for (int cnt = 1; cnt <= 7; cnt++)
    {
        for (int node = 1; node <= 7; node++)
        {
            c.insert(node);
            dfs(node, 1, cnt);
            c.erase(node);
        }
    }
    printf("%d", characters.size());
    return 0;
}
