/*
 * hint:
 * 测试点 2：考察当没有一个数字满足情况时的处理：应当输出一个换行
*/
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int arr[MAXN], ans[MAXN], left_max[MAXN], right_min[MAXN] = {INT32_MAX};

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    left_max[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        left_max[i] = max(left_max[i - 1], arr[i]);
    }
    right_min[n + 1] = INT32_MAX;
    for (int i = n; i >= 1; i--)
    {
        right_min[i] = min(arr[i], right_min[i + 1]);
        if (left_max[i] <= arr[i] && arr[i] <= right_min[i])
            ans[cnt++] = arr[i];
    }
    printf("%d\n", cnt);
    for (int i = cnt - 1; i >= 0; i--)
        printf((i ? "%d " : "%d"), ans[i]);
    printf("\n");
    return 0;
}