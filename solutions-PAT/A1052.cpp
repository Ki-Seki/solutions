/*
 * hint:
 * 链表类型题的一个典型例题
*/
#include <cstdio>
#include <algorithm>
#define MAXN 100001

using namespace std;

struct Node {
    int addr, data, next;
    bool flag;
} nodes[MAXN];

int cmp(Node a, Node b)
{
    if (a.flag != b. flag) return a.flag;
    else return a.data - b.data < 0;
}

int main()
{
    // init flags
    for (int i = 0; i < MAXN; i++)
        nodes[i].flag = false;
    
    // input
    int n, head, addr;
    scanf("%d %d", &n, &head);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &addr);
        scanf("%d %d", &nodes[addr].data, &nodes[addr].next);
        nodes[addr].addr = addr;
    }

    // traversal: mark flags & get count
    int cnt = 0;
    addr = head;
    while (addr != -1)
    {
        nodes[addr].flag = true;
        cnt++;
        addr = nodes[addr].next;
    }

    // output
    if (cnt == 0)
        printf("0 -1\n");
    else
    {
        sort(nodes, nodes + MAXN, cmp);
        printf("%d %05d\n", cnt, nodes[0].addr);
        for (int i = 0; i < cnt; i++)
            printf(i == cnt - 1 ? "%05d %d -1\n" : "%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i+1].addr);
    }
    
    return 0;
}