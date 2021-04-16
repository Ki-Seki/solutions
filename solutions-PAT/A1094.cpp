#include<cstdio>
#include<vector>
#define MAXN 105

using namespace std;

int n, m;
vector<int> tree[MAXN];
int level_cnt_map[MAXN] = {0};  // 从层次号到本层节点数的映射

// root: 该考察 tree[root] 节点了
// level: root 所在的层次号
void dfs(int root, int level)
{
    level_cnt_map[level]++;
    for (int i = 0; i < tree[root].size(); i++)
        dfs(tree[root][i], level + 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int parent, k, child;
        scanf("%d %d", &parent, &k);
        for (int j = 1; j <= k; j++)
        {
            scanf("%d", &child);
            tree[parent].push_back(child);
        }
    }
    dfs(1, 1);
    int max_cnt_level = 1, max_cnt = 1;
    for (int i = 1; i <= n; i++)
        if(level_cnt_map[i] > max_cnt)
        {
            max_cnt_level = i;
            max_cnt = level_cnt_map[i];
        }
    printf("%d %d\n", max_cnt, max_cnt_level);
    return 0;
}
