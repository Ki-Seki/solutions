#include<cstdio>
#include<algorithm>
#include<queue>
#define MAXN 110

using namespace std;

struct Node {
    int data, left, right;
} bst[MAXN];  // 静态的二叉查找树

int n, left, right, numbers[MAXN], len = 0;

void inorder(int root)
{
    if (bst[root].left != -1)
        inorder(bst[root].left);
    bst[root].data = numbers[len++];
    if (bst[root].right != -1)
        inorder(bst[root].right);
}

void layerorder(int root)
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        printf(--n ? "%d " : "%d", bst[index].data);
        if (bst[index].left != -1)
            q.push(bst[index].left);
        if (bst[index].right != -1)
            q.push(bst[index].right);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &left, &right);
        bst[i].left = left;
        bst[i].right = right;
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
    sort(numbers, numbers + n);
    inorder(0);
    layerorder(0);
    return 0;
}
