#include <cstdio>
using namespace std;

int fama[7] = {}, weight[7] = {0, 1, 2, 3, 5, 10, 20};
bool ans[1005];

// 该选择第 i 个砝码，当前重量为 w
void dfs(int i, int w)
{
    // 边界
    if (i == 7)
    {
        ans[w] = true;
        return;
    }

    // 选 j 个 fama[i]
    for (int j = 0; j <= fama[i]; j++)
    {
        w += weight[i] * j;
        fama[i] -= j;
        dfs(i+1, w);
        fama[i] += j;
    }
}

int main()
{
    for (int i = 1; i <= 6; i++) scanf("%d", &fama[i]);
    dfs(1, 0);
    int cnt = 0;
    for (int i = 1; i <= 1002; i++)
        if (ans[i]) cnt++;
    printf("Total=%d\n", cnt);
    return 0;
}