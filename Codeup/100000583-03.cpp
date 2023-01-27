/*  未优化的方法
#include <iostream>
#include <algorithm>
using namespace std;

const int n = 8;  // 8 阶全排列

int p[n + 2], ans[100][n + 2], pos = 1;
bool exist[n + 2] = {};

int perm(int index)
{
    if (index == n + 1)  // 递归边界
    {
        bool isValid = true;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (abs(i - j) == abs(p[i] - p[j]))  // 横纵差相等即在同一斜线
                {
                    isValid = false;
                    break;
                }
        if (isValid)
        {
            for (int i = 1; i <= n; i++)
                ans[pos][i] = p[i];
            pos++;
        }
    }
    else
        for (int x = 1; x <= n; x++)  // 枚举 1 ~ n 所有 x
            if (! exist[x])  // 若 x 未被使用，填在 p[index]
            {
                p[index] = x;
                exist[x] = true;
                perm(index + 1);
                exist[x] = false;
            }
}

int main()
{
    perm(1);
    int tmp;
    scanf("%d", &tmp);
    while(scanf("%d", &tmp) != EOF)
        for (int i = 1; i <= 8; i++)
            printf(i == 8 ? "%d\n" : "%d", ans[tmp][i]);

    return 0;
}
*/

// 事与愿违，优化后的性能并无提升，反而降低
#include <iostream>
#define N 8  // 8 阶全排列
#define SOLVE 92  // 共 92 个解
using namespace std;

int p[N + 2], ans[SOLVE + 10][N + 2], pos = 1;
bool exist[N + 2] = {};

// 现在正在为 p[index] 找合适的值
// cnt 是需要的的合法的八皇后位置的个数
void perm(int index, int cnt)
{
    if (pos > cnt)  // 递归边界：当已经找到足够合法的八皇后位置
        return;
    if (index == N + 1)  // 递归边界：当找到一个合法的八皇后位置
    {
        for (int i = 1; i <= N; i++)  // 保存到 ans 数组
            ans[pos][i] = p[i];
        pos++;
        return;
    }

    // 递归式
    for (int x = 1; x <= N; x++)  // 枚举 1 ~ n 所有 x
        if (! exist[x])  // 若 x 未被使用，填在 p[index]
        {
            // 回溯：若非合法位置，枚举下一个 x
            bool isValid = true;
            for (int i = 1; i < index; i++)
                if (abs(i - index) == abs(p[i] - x))
                {
                    isValid = false;
                    break;
                }
            if (! isValid) continue;

            p[index] = x;
            exist[x] = true;
            perm(index + 1, cnt);
            exist[x] = false;
        }
    return;
}

int main()
{
    int n, b[SOLVE + 100], max_b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > max_b)
            max_b = b[i];
    }
    perm(1, max_b);
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= N; j++)
            printf(j == N ? "%d\n" : "%d", ans[b[i]][j]);
    return 0;
}