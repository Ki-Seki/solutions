#include <cstdio>
#include <algorithm>
#define MAXN 25

using namespace std;

// 定义节点
struct Node {
    int data, height;
    Node *left, *right;
};

// 新节点
Node* new_node(int val)
{
    Node *root = new Node;
    root->data = val;
    root->height = 1;
    root->left = root->right = NULL;
    return root;
}

// 获取树高
int get_height(Node *root)
{
    if (root == NULL) return 0;
    else return root->height;
}

// 获取平衡因子
int get_balance_factor(Node *root)
{
    return get_height(root->left) - get_height(root->right);
}

// 更新树高
void update_height(Node *root)
{
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
}

// 左旋
void left_rotation(Node* &root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    update_height(root);
    update_height(temp);

    root = temp;
}

// 右旋
void right_rotation(Node* &root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;

    update_height(root);
    update_height(temp);

    root = temp;
}

// 插入
void insert(Node* &root, int x)
{
    if (root == NULL)
    {
        root = new_node(x);
        return;
    }
    if (x < root->data)
    {
        insert(root->left, x);
        update_height(root);
        if (get_balance_factor(root) == 2)
        {
            if (get_balance_factor(root->left) == 1)  // LL
                right_rotation(root);
            else if (get_balance_factor(root->left) == -1)  // LR
            {
                left_rotation(root->left);
                right_rotation(root);
            }
        }
    }
    else
    {
        insert(root->right, x);
        update_height(root);
        if (get_balance_factor(root) == -2)
        {
            if (get_balance_factor(root->right) == -1)  // RR
                left_rotation(root);
            else if (get_balance_factor(root->right) == 1)  // RL
            {
                right_rotation(root->right);
                left_rotation(root);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        insert(root, tmp);
    }
    printf("%d", root->data);
}