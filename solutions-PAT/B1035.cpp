/*
 * hint:
 * 未解决！
 * 测试点 2：存在陷阱，初始序列与中间序列相同时的情况
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 105

int n, raw_arr[MAXN], mid_arr[MAXN], cpy_arr1[MAXN], cpy_arr2[MAXN];

void input_arr(int arr[])
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void output_arr(int arr[])
{
    for (int i = 0; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d ", arr[i]);
}

bool is_same(int a[], int b[])
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool sim_insertion_sort()
{
    bool is_ok = false;
    for (int i = 0; i < n; i++)
    {
        // 一趟插入
        int tmp = cpy_arr1[i], j;
        for (j = i - 1; j >= 0; j--)
            if (cpy_arr1[j] > tmp)
                cpy_arr1[j + 1] = cpy_arr1[j];
            else
                break;
        cpy_arr1[j + 1] = tmp;

        // 比较
        if (is_ok && !is_same(raw_arr, cpy_arr1))
        {
            printf("Insertion Sort\n");
            output_arr(cpy_arr1);
            break;
        }
        else
            is_ok = is_same(cpy_arr1, mid_arr);
    }
    return is_ok;
}

bool sim_merge_sort()
{
    bool is_ok = false;
    for (int step = 2; step / 2 < n; step += 2)
    {
        // 一趟归并
        for (int i = 0; i < n; i += step)
            std::sort(cpy_arr2 + i, cpy_arr2 + std::min(i + step, n));
        
        // 比较
        if (is_ok && !is_same(raw_arr, cpy_arr2))
        {
            printf("Merge Sort\n");
            output_arr(cpy_arr2);
            break;
        }
        else
            is_ok = is_same(cpy_arr2, mid_arr);
    }
    return is_ok;
}

int main()
{
    // input
    scanf("%d", &n);
    input_arr(raw_arr);
    input_arr(mid_arr);
    memcpy(cpy_arr1, raw_arr, sizeof(int) * n);
    memcpy(cpy_arr2, raw_arr, sizeof(int) * n);

    // simulate
    if (sim_insertion_sort()) ;
    else if (sim_merge_sort()) ;
    return 0;
}