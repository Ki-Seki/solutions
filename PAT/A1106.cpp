#include<cstdio>
#include<vector>
#include<cmath>
#define MAXN 100005

using namespace std;

int n, lowest_level = MAXN, lowest_level_cnt = 1;
double p, r;
vector<int> tree[MAXN];

// index: 当前节点
// level: 当前层数
void dfs(int index, int level)
{
    if (tree[level].empty())
    {
        if (level < lowest_level)
        {
            lowest_level = level;
            lowest_level_cnt = 0;
        }
        else if (level == lowest_level_cnt)
            lowest_level_cnt++;
        return;
    }
    for (int i = 0; i < tree[index].size(); i++)
        dfs(tree[index][i], level + 1);
}

int main()
{
    scanf("%d %lf %lf", &n, &p, &r);
    lowest_level = n;
    for (int i = 0; i < n; i++)
    {
        int k, id;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &id);
            tree[i].push_back(id);
        }
    }
    dfs(0, 0);
    printf("%.4lf %d\n", p * pow(1.0 + r / 100.0, lowest_level), lowest_level_cnt);
    return 0;
}
