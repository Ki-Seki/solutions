/*
 * hint:
 * 随机选择算法的实践，本质上是一种优化的查询。不存在特定值使其达到 O(n^2)；平均 O(n)
*/
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAXN 10
using namespace std;

unsigned array[MAXN];

// 双指针方法的分割函数的另一种写法
// decreasingly partition the array in [left, right]
int randPartition(int left, int right)
{
    int p = rand() % (right - left) + left;
    swap(array[p], array[left]);

    int prime = left++;  // 主元为初始的 left 值，left 值 然后向后位移一位
    while (left < right)  // until left == right
    {
        while (left < right && array[left] >= array[prime]) left++;
        while (left < right && array[right] < array[prime]) right--;
        swap(array[left], array[right]);
    }
    swap(array[prime], array[left - 1]);  // 交换主元到中间
    return left - 1;
}

// random selection algorithm 随机选择算法
// find the k-th biggest number in [left, right], guarantee left != right
unsigned find_no_k(int left, int right, int k)
{
    if (left == right && k == 1)
        return array[left];
    int pos = randPartition(left, right);
    if (pos + 1 == k)
        return array[pos];
    else if (pos + 1 < k)
        return find_no_k(pos + 1, right, k - pos - 1);
    else
        return find_no_k(left, pos - 1, k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("%d", find_no_k(0, n - 1, k));
    return 0;
}