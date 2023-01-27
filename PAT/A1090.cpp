/*
 * hint:
 * 测试点 3：考察只有一个根节点时候的情况，应当输出原价，数量为 1
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#define MAXN 100005

using namespace std;

int n, deepest_depth = 0, cnt = 1;
double p, r;
struct Node {
    int layer;
    vector<int> child;
} tree[MAXN];

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < tree[front].child.size(); i++)
        {
            int kid = tree[front].child[i];
            tree[kid].layer = tree[front].layer + 1;
            q.push(kid);

            // accquire answers
            if (tree[kid].layer > deepest_depth)
            {
                deepest_depth = tree[kid].layer;
                cnt = 1;
            }
            else if (tree[kid].layer == deepest_depth)
                cnt++;
        }
    }
}

int main()
{
    int tmp, root;
    scanf("%d %lf %lf", &n, &p, &r);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        if (tmp == -1)
            root = i;
        else
            tree[tmp].child.push_back(i);
    }
    tree[root].layer = 0;
    bfs(root);
    printf("%.2lf %d\n", p * pow(1.0 + r / 100.0, deepest_depth), cnt);
    return 0;
}