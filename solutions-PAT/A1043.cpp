#include<cstdio>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

int n;
vector<int> origin, pre, post, pre_mirror, post_mirror;

Node* new_node(int data)
{
    Node* root = new Node;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void insert(Node* &root, int data)
{
    // 递归边界
    if (root == NULL)
    {
        root = new_node(data);
        return;
    }
    
    // 分岔口
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void pre_order(Node* root)
{
    if (root == NULL) return;
    pre.push_back(root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node* root)
{
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    post.push_back(root->data);
}

void pre_mirror_order(Node* root)
{
    if (root == NULL) return;
    pre_mirror.push_back(root->data);
    pre_mirror_order(root->right);
    pre_mirror_order(root->left);
}

void post_mirror_order(Node* root)
{
    if (root == NULL) return;
    post_mirror_order(root->right);
    post_mirror_order(root->left);
    post_mirror.push_back(root->data);
}

int main()
{
    Node* root = NULL;
    // input & initialize
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        origin.push_back(tmp);
        insert(root, tmp);
    }
    pre_order(root);
    post_order(root);
    pre_mirror_order(root);
    post_mirror_order(root);
    if (origin == pre)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf(i == 0 ? "%d" : " %d", post[i]);
    }
    else if (origin == pre_mirror)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf(i == 0 ? "%d" : " %d", post_mirror[i]);
    }
    else
        printf("NO\n");
    return 0;
}
