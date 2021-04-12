#include <cstdio>
#include <queue>
#define MAXN 35

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createByPostIn(int post[], int in[], int postl, int postr, int inl, int inr)
{
    // 递归边界
    if (postl > postr) return NULL;
    Node* root = new Node;
    root->data = post[postr];
    int left_child_len, pos;
    for (pos = inl; pos <= inr; pos++)
        if (post[postr] == in[pos])
        {
            left_child_len = pos - inl;
            break;
        }
    
    // 分岔口
    root->left = createByPostIn(post, in,
                                postl,
                                postl + left_child_len - 1,
                                inl,
                                pos - 1);
    root->right = createByPostIn(post, in,
                                 postl + left_child_len,
                                 postr - 1,
                                 pos + 1,
                                 inr);
    return root;
}

void layerOrder(Node* root, int cnt)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if (cnt-- == 1) printf("%d\n", front->data);
        else printf("%d ", front->data);

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}

int main()
{
    int n, post[MAXN], in[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    Node* root = createByPostIn(post, in, 0, n - 1, 0, n - 1);
    layerOrder(root, n);
    return 0;
}