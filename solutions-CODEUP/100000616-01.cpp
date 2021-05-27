#include <cstdio>
#include <algorithm>
#define MAXN 100005

using namespace std;

// a max heap
int heap[MAXN], size;
int a[MAXN], b[MAXN];

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
        scanf("%d", &a[i]);
    for (int j = 1; j <= size; j++)
        scanf("%d", &b[j]);
    
    // init
    for (int i = 1; i <= size; i++)
        heap[i] = a[i] + b[1];
    create_heap();

    // get min-n
    for (int i = 1; i <= size; i++)
        for (int j = 2; j <= size; j++)
        {
            if (a[i] + b[j] < heap[1])
            {
                heap[1] = a[i] + b[j];
                down_adjust(1, size);
            }
            else
                break;
        }
    heap_sort();
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}