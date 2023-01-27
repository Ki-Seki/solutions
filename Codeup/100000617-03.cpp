#include <cstdio>
#include <queue>
#include <string>
#define MAX_N 1005
#define MAX_ASCII 150

using namespace std;

struct Node
{
    int data;
    char ch;
    Node *left, *right;
};

struct cmp{
    bool operator ()(Node *a, Node *b)
    {
        if (a->data != b->data) return a->data > b->data;
        else return a->ch > b->ch;
    }
};

priority_queue<Node*, vector<Node*>, cmp> q;
char ch[MAX_ASCII];
int ch_cnt[MAX_ASCII];  // map: ch -> cnt
string ch_codes[MAX_ASCII];  // map: ch -> cnt;

void init()
{
    while (q.size()) q.pop();
    for (int i = 0; i < MAX_ASCII; i++)
    {
        ch[i] = '\0';
        ch_cnt[i] = 0;
        ch_codes[i] = "";
    }
}

Node* new_node(int val, char ch)
{
    Node *root = new Node;
    root->data = val;
    root->ch = ch;
    root->left = root->right = NULL;
    return root;
}

Node* merge(Node* a, Node* b)
{
    if (a->ch > a->ch) swap(a, b);
    Node* root = new_node(a->data + b->data, a->ch);
    root->left = a;
    root->right = b;
    return root;
}

void gen_code(Node* root, string init)
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
        ch_codes[root->ch] = init;
    if (root->left != NULL)
        gen_code(root->left, init + "0");
    if (root->right != NULL)
        gen_code(root->right, init + "1");
}

int main()
{
    int n;
    while (scanf("%d\n", &n) == 1)
    {
        init();
        int tmp;
        for (int i = 1; i <= n; i++)
        {
            scanf("%c %d\n", &ch[i], &tmp);
            ch_cnt[ch[i]] = tmp;
            q.push(new_node(tmp, ch[i]));
        }
        while (q.size() > 1)
        {
            Node* first = q.top(); q.pop();
            Node* second = q.top(); q.pop();
            q.push(merge(first, second));
        }
        gen_code(q.top(), "");
        for (int i = 1; i <= n; i++)
            printf("%c:%s\n", ch[i], ch_codes[ch[i]].c_str());
    }
    return 0;
}