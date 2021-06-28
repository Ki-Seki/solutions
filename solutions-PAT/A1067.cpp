/*
 * hint:
 * 1. 测试点1，2：当 0 已经回到原位，向下寻找没有归位的值的时候，要进行优化。具体就是记录当前最小的未归位的下标
 * 2. 测试点3：初始时，0 就已经在原位
*/
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int numbers[MAXN] = {};

int main()
{
    int n, tmp, cnt;
    scanf("%d", &n);
    cnt = n - 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        numbers[tmp] = i;
        if (tmp == i && tmp != 0) cnt--;
    }
    int ans = 0, i = 1;
    while (cnt > 0)
    {
        if (numbers[0] != 0)
        {
            swap(numbers[0], numbers[numbers[0]]);
            cnt--;
        }
        else
        {
            for (; i < n; i++)
                if (numbers[i] != i)
                {
                    swap(numbers[0], numbers[i]);
                    break;
                }
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}