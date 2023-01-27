/*
 * hint:
 * cmp() 函数必须用 bool 作为返回值
 * 
 * 易错点：若将 cmp 函数中“>”改为“>=”，则测试点 5 会出现段错误
 * 原因是：可能会造成值全相等时的循环比较
*/
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#define MAXN 105

using namespace std;

int n, m, s;
struct Node {
    int weight;
    vector<int> child;
} tree[MAXN];
vector<int> path;

bool cmp(int a, int b)
{
    return tree[a].weight > tree[b].weight;
}

// index: 已取 index 号节点，考察 index 的子节点
// sum: 当前所选节点的权重和
// s: 目标权重和
void dfs(int index, int sum, int s)
{
    // 递归边界
    if (index >= n || sum > s) return;
    if (sum == s)
    {
        if (!tree[path.back()].child.empty()) return;
        for (int i = 0; i < path.size(); i++)
            printf(i == path.size() - 1 ? "%d\n" : "%d ", tree[path[i]].weight);
        return;
    }

    // 循环分岔口
    for (int i = 0; i < tree[index].child.size(); i++)
    {
        int kid = tree[index].child[i];
        path.push_back(kid);
        dfs(kid, sum + tree[kid].weight, s);
        path.pop_back();
    }
}

int main()
{
    // input & sort
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &tree[i].weight);
    for (int i = 0; i < m; i++)
    {
        int id, k, kid_id;
        scanf("%d %d", &id, &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &kid_id);
            tree[id].child.push_back(kid_id);
        }
        // non-increasing sort
        sort(tree[id].child.begin(), tree[id].child.end(), cmp);
    }

    // dfs
    path.push_back(0);
    dfs(0, tree[0].weight, s);
    return 0;
}