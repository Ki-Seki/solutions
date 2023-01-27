/*
 * 本题使用两种方法，均通过评测：
 * 归并 + 直接排序
*/

// 用归并算法
#include <iostream>
#include <limits.h>
#define MAXN 1000005
using namespace std;

long arr1[MAXN], arr2[MAXN];

int main()
{
    // input
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        scanf("%ld", &arr1[i]);
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        scanf("%ld", &arr2[i]);
    
    // optimize
    arr1[n1] = arr2[n2] = LONG_MAX;
    
    // simulate merging
    int p1 = 0, p2 = 0, p_mid = (n1 + n2 - 1) / 2, p = 0;
    long tmp;
    while (p <= p_mid)
    {
        tmp = (arr1[p1] <= arr2[p2]) ? (arr1[p1++]) : (arr2[p2++]);
        p++;
    }
    printf("%ld", tmp);
    return 0;
}

// // 用系统自带的排序
// #include <iostream>
// #include <algorithm>
// #define MAXN 1000005
// using namespace std;

// long long arr[MAXN * 2];

// int main()
// {
//     int n1, n2;
//     scanf("%d", &n1);
//     for (int i = 0; i < n1; i++)
//         scanf("%lld", &arr[i]);
//     scanf("%d", &n2);
//     for (int i = n1; i < n1 + n2; i++)
//         scanf("%lld", &arr[i]);
//     sort(arr, arr + n1 + n2);
//     printf("%lld", arr[(n1 + n2 - 1) / 2]);
//     return 0;
// }