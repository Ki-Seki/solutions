#include <cstdio>
#include <vector>
#define MAXN 12

using namespace std;

int n;
vector<int> ans;
bool is_existed[MAXN] = {}, has_ans = false;

void output()
{
    for (int i = 0 ; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d ", ans[i]);
}

// 判断前 n 个元素是否合法，即是否符合 8 皇后问题
bool is_valid(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (j - i == ans[j] - ans[i] ||
                i - j == ans[j] - ans[i])
                return false;
    return true;
}

void dfs(int now_cnt)
{
    // 递归边界
    if (now_cnt == n && is_valid(n))
    {
        output();
        has_ans = true;
        return;
    }

    // 循环分岔口
    for (int i = 1; i <= n; i++)
        if (!is_existed[i])
        {
            if (!is_valid(now_cnt)) return;  // 剪枝
            ans.push_back(i);
            is_existed[i] = true;
            dfs(now_cnt + 1);
            ans.pop_back();
            is_existed[i] = false;
        }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    if (!has_ans) printf("no solute!");
    return 0;
}