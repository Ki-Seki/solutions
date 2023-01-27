#include <stdio.h>
#include <stdbool.h>
#define MAXN 100005
int a[MAXN], n;

bool is_maxheap(int node)
{
    
    if (node > n) return true;
    if (node * 2 <= n && a[node] < a[node*2]) return false;
    if (node * 2 + 1 <= n && a[node] < a[node*2+1]) return false;
    return is_maxheap(node*2) && is_maxheap(node*2+1);
}

bool is_minheap(int node)
{
    
    if (node > n) return true;
    if (node * 2 <= n && a[node] > a[node*2]) return false;
    if (node * 2 + 1 <= n && a[node] > a[node*2+1]) return false;
    return is_minheap(node*2) && is_minheap(node*2+1);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (is_maxheap(1))
            printf("Max heap\n");
        else if (is_minheap(1))
            printf("Min heap\n");
        else
            printf("Not a heap!\n");
    }
    return 0;
}