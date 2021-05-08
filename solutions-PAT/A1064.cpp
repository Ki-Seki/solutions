/*
 * hint:
 * 本题用到的关于二叉树性质：
 * 1. CBT 按照数组存放时的下标关系
 * 2. 二叉查找树的中序遍历结果是有序的
 * 3. 存在线性表中的 CBT 是层序遍历的结果
 * 
 * 做有关树的题时，要注意联系遍历
*/
#include<cstdio>
#include<algorithm>
#define MAXN 1010

using namespace std;

int cbt[MAXN] = {}, n,
    numbers[MAXN], curr;

void inorder(int index)
{
    if (index > n) return;
    inorder(2 * index);
    cbt[index] = numbers[curr++];
    inorder(2 * index + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)  // 从 1 开始，方便操作 CBT
        scanf("%d", &numbers[i]);
    curr = 1;
    sort(numbers + 1, numbers + n + 1);
    inorder(1);
    for (int i = 1; i <= n; i++)
        printf(i == 1 ? "%d" : " %d", cbt[i]);
    return 0;
}
