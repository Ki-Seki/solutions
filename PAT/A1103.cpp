#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 400
#define MAX_SQRT_N 20

int n, k, p,  // input data
    max_fac_sum = -1, ans_list[MAXN],  // answer related
    tmp_list[MAXN], tmp_i = 0;  // temporary variables

// 深度优先搜索：
// 当前要考察 index，
// 已选了 now_K 个，
// 已选元素次方和为 sum，
// 已选元素的因子和为 fac_sum
void dfs(int index, int now_k, int sum, int fac_sum)
{
    if (now_k > k || sum > n || index < 1) return;
    else if (now_k == k && sum == n)
    {
        if (fac_sum > max_fac_sum)
        {
            memcpy(ans_list, tmp_list, sizeof(ans_list));
            max_fac_sum = fac_sum;
        }
        return;
    }
    else
    {
        // 选择 index
        tmp_list[tmp_i++] = index;
        dfs(index, now_k + 1, sum + pow(index, p), fac_sum + index);
        tmp_i--;

        // 不选 index
        dfs(index - 1, now_k, sum, fac_sum);
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &p);
    dfs(MAX_SQRT_N, 0, 0, 0);
    if (max_fac_sum != -1)
    {
        printf("%d = ", n);
        for (int i = 0; i < k; i++)
            printf(i == k - 1 ? "%d^%d" : "%d^%d + ", ans_list[i], p);
    }
    else
        printf("Impossible\n");
    return 0;
}