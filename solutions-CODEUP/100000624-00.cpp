/*
 * hint:
 * 做出合理假设：
 * 1. 输入部分的字符集，总是字典序排列的，并且字母间不间断
 * 2. 存在等价关键路径时，输出字典序小的
 * 3. 源点是 a
 * 
 * 输入字符型变量时，可以这样避免读入 '\n'：
 * scanf("\n%c %c %d", &s, &e, &w);
 * 或者这样
 * scanf("%*c%c %c %d", &s, &e, &w);  // %*c 用于省略一个输入项，用处更广泛
*/
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#define MAXV 17

using namespace std;

struct Node {
    int v, time;  // 邻接节点，两节点间时间权重
};

int n, x, y;  // 测试数据数目，节点数，边数
char vertex_set[MAXV];  // 节点字符集
vector<Node> adj[MAXV];  // 图的邻接表
int in_degree[MAXV];  // 节点入度
int ve[MAXV], vl[MAXV];
stack<int> topo_order;  // 正拓扑序列

void init()
{
    memset(vertex_set, '\0', sizeof(vertex_set));
    for (int i = 0; i < MAXV; i++) adj[i].clear();
    // ve[] & vl[] are initialized in critical_path()
    memset(in_degree, 0, sizeof(in_degree));
    while (topo_order.size()) topo_order.pop();
}

// do topological sort
// get topological sequence and store it in topo_order
// calculate ve[]
// return boolean value indicating the existence of cycle
bool topological_sort()
{
    queue<int> s;
    for (int i = 0; i < x; i++)
        if (in_degree[i] == 0)
            s.push(i);
    while (s.size())
    {
        int u = s.front();
        s.pop();
        topo_order.push(u);
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v, time = adj[u][i].time;
            in_degree[v]--;
            if (in_degree[v] == 0)
                s.push(v);
            // u -> v, use ve[u] to update ve[v]
            if (ve[u] + time > ve[v])
                ve[v] = ve[u] + time;
        }
    }
    if (topo_order.size() == x) return true;
    else return false;
}

int critical_path()
{
    // step 1: get ve[]
    memset(ve, 0, sizeof(ve));
    if (topological_sort() == false)
        return -1;
    // step 2: get vl[]
    int critical_length = 0;  // 当汇点未知时
    for (int i = 0; i < x; i++)
        if (ve[i] > critical_length)
            critical_length = ve[i];
    fill(vl, vl + x, critical_length);  // 因为所有 vl[] 必定小于 ve[x - 1]，当然也可以赋值 MAX
    while (topo_order.size())
    {
        int u = topo_order.top();
        topo_order.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v, time = adj[u][i].time;
            // u -> v, use vl[v] to update vl[u]
            if (vl[v] - time < vl[u])
                vl[u] = vl[v] - time;
        }
    }
    // step 3: traverse all edges to calculate e & l
    for (int u = 0; u < x; u++)
        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].v, time = adj[u][i].time;
            int e = ve[u], l = vl[v] - time;
            if (e == l)
            {
                printf("(%c,%c) ", vertex_set[u], vertex_set[v]);  // a section of critical path
                // two statements below are to avoid outputing another critical path with same length
                u = v - 1;  // 令下一次的起点 u 为当前的终点 v 减去一，循环结束时的“u++”发挥总用，让 u 成为现在的 v
                break;  // 跳出内循环，防止另一条路径的输出
            }
        }
    // step 4: return length of critical path
    return critical_length;
}

int main()
{
    scanf("%d", &n);
    while (n--)  // n cases
    {
        init();
        scanf("%d %d%s", &x, &y, vertex_set);
        for (int i = 0; i < y; i++)
        {
            char s, e;
            int w;
            scanf("\n%c %c %d", &s, &e, &w);
            adj[s - 'a'].push_back({e - 'a', w});
            in_degree[e-'a']++;
        }
        int len = critical_path();
        printf("%d\n", len);
    }
    return 0;
}