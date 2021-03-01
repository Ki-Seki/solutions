/*
 * 本题尝试了四种方法，三种通过测试，一种不可用
 * 1. 哈希桶排序：利用桶排序读入数据，从小到大遍历数组
 * 2. 二分查找：读入数据并按普通方法排序，对数组每一个元素 a[i]，二分查找 m - a[i]
 * 3. 哈希桶排序 + 二分查找：不可用，因为哈希桶排序消去了二分查找时的种植可比性
 * 4. 双指针：排序后通过前后指针向中间靠近
*/

// // 哈希桶排序
// #include <iostream>
// #define MAX_M 1005
// using namespace std;

// int coins[MAX_M] = {};

// int main()
// {
//     int n, m, coin;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &coin);
//         coins[coin]++;
//     }
//     for (int i = 0; i < MAX_M / 2; i++)
//     {
//         if (coins[i] > 0)
//         {
//             coins[i]--;  // avoid error when i == m - i
//             if (coins[m - i] > 0)
//             {
//                 printf("%d %d", i, m - i);
//                 return 0;
//             }
//         }
//     }
//     printf("No Solution");
//     return 0;
// }

// // 二分查找
// #include <iostream>
// #include <algorithm>
// #define MAX_N 100005
// using namespace std;

// int coins[MAX_N] = {};

// int binarySearch(int low, int high, int x)
// {
//     int mid;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (coins[mid] == x)
//             return mid;
//         else if (coins[mid] < x)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return -1;
// }

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &coins[i]);
//     sort(coins, coins + n);
//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         ans = binarySearch(i + 1, n - 1, m - coins[i]);
//         if (ans != -1) break;
//     }
//     if (ans != -1)
//         printf("%d %d", m - coins[ans], coins[ans]);
//     else
//         printf("No Solution");
//     return 0;
// }

// // 哈希桶排序 + 二分查找
// #include <iostream>
// #define MAX_FACE_VALUE 505
// using namespace std;

// int coins[MAX_FACE_VALUE] = {};

// int main()
// {
//     // input && init
//     int n, m, coin;
//     scanf("%d %d", &n, &m);
//     int low = 505, high = -1;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &coin);
//         coins[coin]++;
//         if (coin > high) high = coin;
//         if (coin < low) low = coin;
//     }

//     // binary search
//     // 实践证明，无法用桶排序 + 二分查找结合的方法。二分查找的关键就在于：中值可比性；而桶排序消除了中值可比性
//     while (low < high)
//     {
//         int mid = (low + high) /2;
//         if (m - mid <= 500 && m - mid != m)
//             if (coins[mid] && coins[m - mid])
//                 high = mid;
//             else
//     }

//     printf("No Solution");
//     return 0;
// }

// 双指针
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int a[MAXN], n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (a[left] + a[right] == m) break;
        else if (a[left] + a[right] < m) left++;
        else right--;
    }
    if (left != right && a[left] + a[right] == m)
        printf("%d %d", a[left], a[right]);
    else
        printf("No Solution");
    return 0;
}