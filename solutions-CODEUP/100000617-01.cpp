/*
 * 哈夫曼编码
 *
 * 本题并未通过测试，这是因为哈夫曼的最优编玛并不唯一
 * 而本题所使用的方法生成的前缀编码与题中的差异来自系统性差异，不可解决
 * 本题的代码仍然非常具有参考性
*/
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#define MAXN 105

using namespace std;

// 普通二叉树节点
struct Node {
    int data;
    Node *left, *right;
};

int data[MAXN];  // 输入数据
string code[MAXN];  // 以数据为键，保存数据的前缀编码

// 小顶堆：保存指向树的指针
// 之所以保存指针，而不保存值，是因为保存值就会有被覆盖的风险，而导致已构造的哈夫曼树被破坏
Node* heap[MAXN];
int size;

// 二叉树：新建节点，这个节点值是用 new 运算符生成的，因此并非临时的
Node* new_node(int val)
{
    Node* root = new Node;
    root->data = val;
    root->left = root->right = NULL;
    return root;
}

// 堆：初始化，data 从 1 开始计数
void init(int data[], int n)
{
    size = n;
    for (int i = 1; i <= n; i++)
        heap[i] = new_node(data[i-1]);
}

// 堆：向下调整 [low, high]
void down_adjust(int low, int high)
{
    int node = low, min_child = node * 2;
    while (min_child <= high)
    {
        if (min_child + 1 <= high && heap[min_child+1]->data < heap[min_child]->data)
            min_child++;
        if (heap[min_child]->data < heap[node]->data)
        {
            swap(heap[node], heap[min_child]);
            node = min_child;
            min_child = node * 2;
        }
        else
            break;
    }
}

// 堆：向上调整 [low, high]
void up_adjust(int low, int high)
{
    int node = high, parent = high / 2;
    while (parent >= low)
    {
        if (heap[node]->data < heap[parent]->data)
        {
            swap(heap[node], heap[parent]);
            node = parent;
            parent = node / 2;
        }
        else
            break;
    }
}

// 堆：建堆
void create_heap()
{
    for (int i = size / 2; i >= 1; i--)
        down_adjust(i, size);
}

// 堆：删除堆顶元素
void delete_top()
{
    heap[1] = heap[size--];
    down_adjust(1, size);
}

// 堆：插入新元素
void insert(Node* x)
{
    heap[++size] = x;
    up_adjust(1, size);
}

// 堆：弹出堆顶指针元素，并删除堆顶
Node* pop()
{
    Node* top = heap[1];
    delete_top();
    return top;
}

// 哈夫曼树：合并两个节点，返回合并后的根节点指针
Node* merge(Node* a, Node* b)
{
    Node* root = new_node(a->data + b->data);
    root->left = a;
    root->right = b;
    return root;
}

// 哈夫曼树：建树
Node* create_huffman()
{
    create_heap();
    while (size > 1)
    {
        Node* first = pop();
        Node* second = pop();
        insert(merge(first, second));
    }
    return heap[1];
}

// 哈夫曼树：生成哈夫曼编码，一般为 init 赋值 ""
// 哈夫曼编码结果
void gen_code(Node* root, string init)
{
    // 递归终止条件
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)  // 只有叶子节点才有前缀编码
        code[root->data] = init;
    else
    {
        gen_code(root->left, init + "0");
        gen_code(root->right, init + "1");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    init(data, n);
    Node* root = create_huffman();
    gen_code(root, "");
    for (int i = 0; i < n; i++)
        cout << code[data[i]] << endl;
    return 0;
}