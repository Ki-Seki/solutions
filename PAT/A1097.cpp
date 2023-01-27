#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define MAX_KEY 10005

using namespace std;

// step 1: define
struct Node {
    int addr, data, next, order;
} list[MAXN];

bool is_existed[MAX_KEY] = {};

int cmp(Node a, Node b)
{
    return a.order < b.order;
}

int main()
{
    // step 2: initialize
    for (int i = 0; i < MAXN; i++)
        list[i].order = 2 * MAXN;  // set all as invalid data
    
    int head, n;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++)
    {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &list[addr].data, &list[addr].next);
        list[addr].addr = addr;
    }

    // step 3: purge
    int remain_cnt = 0, removed_cnt = 0, p = head;
    while (p != -1)
    {
        int data = list[p].data * (list[p].data < 0 ? -1 : 1);
        if (is_existed[data])
            list[p].order = MAXN + removed_cnt++;
        else
        {
            list[p].order = remain_cnt++;
            is_existed[data] = true;
        }
        p = list[p].next;
    }

    // step 4: sort
    sort(list, list + MAXN, cmp);

    // step 5: output
    for (int i = 0; i < remain_cnt; i++)
        printf(i == remain_cnt - 1 ? "%05d %d -1\n" : "%05d %d %05d\n", list[i].addr, list[i].data, list[i+1].addr);
    for (int i = remain_cnt; i < remain_cnt + removed_cnt; i++)
        printf(i == remain_cnt + removed_cnt - 1 ? "%05d %d -1\n" : "%05d %d %05d\n", list[i].addr, list[i].data, list[i+1].addr);
    return 0;
}