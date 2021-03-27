#include <cstdio>
#define MAXN 100010

struct {
    char data;
    int next;
    bool flag;
} nodes[MAXN];

int main()
{
    // init
    for (int i = 0; i < MAXN; i++)
        nodes[i].flag = false;
    
    // input
    int head1, head2, n;
    scanf("%d %d %d", &head1, &head2, &n);
    for (int i = 0; i < n; i++)
    {
        int addr, next;
        char data;
        scanf("%d %c %d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
    }

    // traversal of the first word
    while (head1 != -1)
    {
        nodes[head1].flag = true;
        head1 = nodes[head1].next;
    }

    // traversal of the second word
    while (head2 != -1)
    {
        if (nodes[head2].flag) break;
        head2 = nodes[head2].next;
    }
    if (head2 == -1)
        printf("-1");
    else
        printf("%05d", head2);
    return 0;
}