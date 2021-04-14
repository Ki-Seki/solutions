#include <cstdio>
#include <vector>
#include <cmath>
#define MAXN 100005

using namespace std;

int n;
double p, r;
struct Node {
    int amount;
    vector<int> child;
} tree[MAXN];

// root: 考察过 root 节点，该考察 root 的子节点
// layer: root 所在的 layer
double dfs(int root, int layer)
{
    // 递归边界
    if (tree[root].amount != -1)  // if is leaf node
        return tree[root].amount * p * pow(1.0 + r / 100.0, layer);
    
    double ans = 0;
    // 循环分岔口
    for (int i = 0; i < tree[root].child.size(); i++)
        ans += dfs(tree[root].child[i], layer + 1);
    return ans;
}

int main()
{
    // input
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        int k, id;
        scanf("%d", &k);
        if (k == 0)
            scanf("%d", &tree[i].amount);
        else
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &id);
                tree[i].child.push_back(id);
                tree[i].amount = -1;  // 若不是零售商，数量标为 -1
            }
    }

    // output
    printf("%.1lf", dfs(0, 0));
    return 0;
}