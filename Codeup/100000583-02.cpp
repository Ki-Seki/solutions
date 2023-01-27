/*
 * hint:
 * 递归题的关键就是找清楚 递归边界 和 递归式
*/
#include <iostream>
#define MAXN 25
using namespace std;

const int capacity = 40;
int things[MAXN], cnt;

// 决策是否选择 things[index]
// 当前重量为 curr_weight
int choice(int index, int curr_weight)
{
    // 递归边界
    if (curr_weight == capacity)
        return 1;
    if (index > cnt || curr_weight > capacity)
        return 0;

    // 递归式
    return choice(index + 1, curr_weight + things[index]) + choice(index + 1, curr_weight);
}

int main()
{
    while (scanf("%d", &cnt) != EOF)
    {
        for (int i = 1; i <= cnt; i++)
            scanf("%d", &things[i]);
        printf("%d\n", choice(1, 0));
    }
    return 0;
}