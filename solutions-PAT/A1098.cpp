#include <cstdio>
#include <algorithm>
#define MAXN 105

using namespace std;

// start from 1
int heap[MAXN], size,  // max heap
    init[MAXN], sorting[MAXN];

void down_adjust(int low, int high)
{
    int node = low, max_child = node * 2;
    while (max_child <= high)
    {
        if (max_child + 1 <= high && heap[max_child + 1] > heap[max_child])
            max_child++;
        if (heap[node] < heap[max_child])
        {
            swap(heap[node], heap[max_child]);
            node = max_child;
            max_child = node * 2;
        }
        else
            break;
    }
}

void create_heap()
{
    for (int i = size / 2; i >= 1; i--)
        down_adjust(i, size);
}

bool is_equal(int a[], int b[], int n)
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

void output(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        printf(i == n ? "%d" : "%d ", a[i]);
}

int main()
{
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &init[i]);
        heap[i] = init[i];
    }
    for (int i = 1; i <= size; i++)
        scanf("%d", &sorting[i]);
    
    // simulate insertion sort
    bool flag = false;
    for (int i = 2; i <= size; i++)
    {
        int temp = init[i], j;
        for (j = i - 1; j >= 1; j--)
            if (temp < init[j])
                init[j + 1] = init[j];
            else
                break;
        init[j + 1] = temp;

        // detection
        if (flag == false && is_equal(init, sorting, size))
            flag = true;
        else if (flag == true)
        {
            printf("Insertion Sort\n");
            output(init, size);
            return 0;
        }
    }

    // simulate heap sort
    flag = false;
    create_heap();
    int n = size;
    while (n >= 1)
    {
        swap(heap[1], heap[n--]);
        down_adjust(1, n);

        // detection
        if (flag == false && is_equal(heap, sorting, size))
            flag = true;
        else if (flag == true)
        {
            printf("Heap Sort\n");
            output(heap, size);
            return 0;
        }
    }
    return 0;
}