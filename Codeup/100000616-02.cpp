#include <cstdio>
#include <algorithm>
#define MAXN 30005

using namespace std;

// a min heap
int heap[MAXN], size;

void down_adjust(int low, int high)
{
    int node = low, max_child = node * 2;
    if (max_child > high)
        return;
    if (max_child + 1 <= high && heap[max_child+1] < heap[max_child])
        max_child++;
    if (heap[max_child] < heap[node])
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

void delete_top()
{
    heap[1] = heap[size];
    down_adjust(1, --size);
}

int pop()
{
    int top = heap[1];
    delete_top();
    return top;
}

void up_adjust(int low, int high)
{
    int node = high, parent = node / 2;
    if (parent < low)
        return;
    if (heap[node] < heap[parent])
    {
        swap(heap[node], heap[parent]);
        up_adjust(low, parent);
    }
}

void insert(int x)
{
    heap[++size] = x;
    up_adjust(1, size);
}

int main()
{
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
        scanf("%d", &heap[i]);
    create_heap();
    int energy = 0;
    while (size > 1)
    {
        int tmp = pop() + pop();
        insert(tmp);
        energy += tmp;
    }
    printf("%d", energy);
    return 0;
}