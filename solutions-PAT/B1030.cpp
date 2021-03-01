// 双指针的方法，效率：O(n)
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long LL;

int arr[MAXN];

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int max_len = -1, pi = 0, pj = 0;
    while (pj < n)
    {
        while (pj < n && arr[pj] <= (LL) arr[pi] * p) pj++;
        if (max_len < (pj - pi)) max_len = pj - pi;
        pi++;
    }
    printf("%d", max_len);
    return 0;
}

// // 二分查找的方法，效率：O(nlogn)
// #include <iostream>
// #include <algorithm>
// #define MAXN 100005
// using namespace std;

// long long array[MAXN];

// int main()
// {
//     long long n, p;
//     scanf("%lld %lld", &n, &p);
//     for (int i = 0; i < n; i++) scanf("%lld", &array[i]);
//     sort(array, array + n);
//     int max = -1;
//     for (int i = 0; i < n; i++)
//     {
//         // find the upper bound
//         int front = i + 1, tail = n - 1, mid;
//         while (front <= tail)
//         {
//             mid = (front + tail) / 2;
//             if (array[mid] <= array[i] * p)
//                 front = mid + 1;
//             else
//                 tail = mid - 1;
//         }
//         // end of finding upper bound
//         if (front - i + 1 > max) max = front - i;

//         /* 下面这两行代码等价于上述循环体内容，
//         int j = upper_bound(array + i + 1, array + n, array[i] * p) - array;
//         max = std::max(max, j);
//         */
//     }
//     printf("%d", max);
//     return 0;
// }