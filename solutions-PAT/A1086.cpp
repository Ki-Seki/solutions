#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 32

using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

int n, pre[MAXN], in[MAXN];

void input()
{
    char code[5];
    int number, pre_i = 0, in_i = 0;
    stack<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++)
    {
        scanf("%s", code);
        if (strcmp(code, "Push") == 0)
        {
            scanf("%d", &number);
            pre[pre_i++] = number;
            s.push(number);
        }
        else
        {
            in[in_i++] = s.top();
            s.pop();
        }
    }
}

Node* createByPreIn(int prel, int prer, int inl, int inr)
{
    // 递归边界
    if (prel > prer) return NULL;

    // 保存当前序列根节点
    int root_data = pre[prel];
    Node *root = new Node;
    root->data = root_data;

    // 找到当前序列根节点在 inoreder 中的位置和 左子树节点数
    int pos, left_len;
    for (pos = inl; pos <= inr; pos++)
        if (in[pos] == root_data)
        {
            left_len = pos - inl;
            break;
        }

    // 分岔口
    root->left = createByPreIn(
        prel + 1,
        prel + left_len,
        inl,
        pos - 1
    );
    root->right = createByPreIn(
        prel + left_len + 1,
        prer,
        pos + 1,
        inr
    );
    return root;
}

void postorder(Node *root)
{
    if (root->left) postorder(root->left);
    if (root->right) postorder(root->right);
    printf(n-- != 1 ? "%d " : "%d\n", root->data);
}

int main()
{
    input();
    Node *root = createByPreIn(0, n - 1, 0, n - 1);
    postorder(root);
    return 0;
}