#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 1010

using namespace std;

struct Mouse {
    int weight, rank;
} mice[MAXN];

queue<int> order;

void process_a_group(int cnt, int rank)
{
    int max = order.front();
    order.pop();
    for (int j = 1; j < cnt; j++)
    {
        if (mice[order.front()].weight > mice[max].weight)
        {
            mice[max].rank = rank;
            max = order.front();
        }
        else
            mice[order.front()].rank = rank;
        order.pop();
    }
    order.push(max);
}

int main()
{
    int np, ng;
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++)
        scanf("%d", &mice[i].weight);
    for (int i = 0; i < np; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        order.push(tmp);
    }
    while (!order.empty())
    {
        // special judge
        if (order.size() == 1)
        {
            mice[order.front()].rank = 1;
            order.pop();
            break;
        }

        int last_group = order.size() % ng,  // 最后一组的数量
            group = order.size() / ng,  // 向下取整的组数
            rank = group + (last_group ? 1 : 0) + 1;  // 本轮未晋级的选手的共同排名
        for (int i = 0; i < group; i++)
            process_a_group(ng, rank);
        if (last_group)  // 若有不完整的组
            process_a_group(last_group, rank);
    }
    for (int i = 0; i < np; i++)
        printf(i == np - 1 ? "%d\n" : "%d ", mice[i].rank);
    return 0;
}