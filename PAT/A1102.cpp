/*
 * hint:
 * 格式化输入，“scanf("%*c%c %c", &l, &r);”中 
 * “%*c”可以使这个位置的值被忽略
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 12

using namespace std;

int n, root, cnt;
struct Node {
    // int data;  // 本题不需要数据域
    int left, right;
} tree[MAXN];

void invert(int root)
{
    if (root == -1) return;
    invert(tree[root].left);
    invert(tree[root].right);
    swap(tree[root].left, tree[root].right);
}

void layerorder(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        printf(++cnt < n ? "%d " : "%d\n", front);
        if (tree[front].left != -1)
            q.push(tree[front].left);
        if (tree[front].right != -1)
            q.push(tree[front].right);
    }
}

void inorder(int root)
{
    if (root == -1) return;
    inorder(tree[root].left);
    printf(++cnt < n ? "%d " : "%d\n", root);
    inorder(tree[root].right);
}

int main()
{
    bool not_root[MAXN] = {};

    // input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char l, r;
        scanf("%*c%c %c", &l, &r);  // 忽略 '\n' 影响输入两个字符
        tree[i].left = (l == '-' ? -1 : l - '0');
        tree[i].right = (r == '-' ? -1 : r - '0');
        if (l != '-') not_root[l - '0'] = true;
        if (r != '-') not_root[r - '0'] = true;
    }

    // find root node
    for (root = 0; root < n; root++)
        if (not_root[root] == false)
            break;
    
    // invert the binary tree
    invert(root);

    // output
    cnt = 0;
    layerorder(root);
    cnt = 0;
    inorder(root);
    return 0;
}