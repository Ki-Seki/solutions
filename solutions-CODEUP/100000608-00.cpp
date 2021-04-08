#include <cstdio>
#define MAXN 12

// 利用 dfs 递归实现的全排列
// 当前要考察 index
// 已选了 n 个数字
// 结果暂存数组为 arr[]
// 是否被选过的标记数组为 is_existed[]
void dfs_permutation(int index, int n, int arr[], bool is_existed[])
{
    if (index == n + 1)  // 已选够元素，输出
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!is_existed[i])
        {
            arr[index] = i;
            is_existed[i] = true;
            dfs_permutation(index + 1, n, arr, is_existed);
            is_existed[i] = false;
        }
    }
}

int main()
{
    int n, arr[MAXN];
    bool is_existed[MAXN] = {};
    scanf("%d", &n);
    dfs_permutation(1, n, arr, is_existed);
    return 0;
}