#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

// a max heap
int heap[MAXN], size;

void down_adjust(int low, int high)
{
    int node = low, max_child = node * 2;
    if (max_child > high)
        return;
    if (max_child + 1 <= high && heap[max_child+1] > heap[max_child])
        max_child++;
    if (heap[max_child] > heap[node])
    {
        swap(heap[max_child], heap[node]);
        down_adjust(max_child, high);
    }
}

void create_heap()
{
    for (int i = size / 2; i >= 1; i--)
        down_adjust(i, size);
}

void heap_sort()
{
    int n = size;
    while (n)
    {
        swap(heap[1], heap[n]);
        down_adjust(1, --n);
    }
}

int main()
{
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
        scanf("%d", &heap[i]);
    create_heap();
    heap_sort();
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}