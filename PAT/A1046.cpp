/*
 * hint:
 * 估计程序运行时间：如果要求200ms，那么语句不要超过(200±25)*10个
*/

#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int dis[MAXN], n, m, sum = 0;

int main()
{
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        sum += tmp;
        dis[i] = sum;
    }
    cin >> m;
    int left, right;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &left, &right);
        tmp = (left < right ? 1 : -1) * (dis[right-1] - dis[left-1]);
        printf("%d\n", min(tmp, sum - tmp));
    }
    return 0;
}