/*
 * hint:
 * 本题采用两种方法：
 * 
 * 方法一：将有效节点保存至一个 vector 数组，通过 reverse 函数求反
 * 
 * 方法二：根据模板，仅利用数组来求解，区间逆序输出即可
 * 
 * ps. 模板大纲：define -> initialize -> purge -> sort -> output
*/


// // 方法一
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #define MAXN 100010

// using namespace std;

// struct Node{
//     int addr, data, next;
// } tmp[MAXN];

// vector<Node> ans;

// int main()
// {
//     int head, n, k;
//     scanf("%d %d %d", &head, &n, &k);
//     for (int i = 0; i < n; i++)
//     {
//         int addr;
//         scanf("%d", &addr);
//         scanf("%d %d", &tmp[addr].data, &tmp[addr].next);
//         tmp[addr].addr = addr;
//     }
//     while (head != -1)
//     {
//         ans.push_back(tmp[head]);
//         head = tmp[head].next;
//     }
//     for (int i = 0; i < ans.size() / k; i++)
//         reverse(ans.begin() + i * k, ans.begin() + i * k + k);
//     for (int i = 0; i < ans.size(); i++)
//         printf(i == ans.size() - 1 ? "%05d %d -1\n" : "%05d %d %05d\n", ans[i].addr, ans[i].data, ans[i + 1].addr);
//     return 0;
// }

// 方法二
#include <cstdio>
#include <algorithm>
#define MAXN 100010

using namespace std;

// step 1: define
struct Node {
    int addr, data, next, order;
} nodes[MAXN];

int cmp(Node a, Node b)
{
    return a.order < b.order;
    // 如果改成 return a.order - b.order < 0; 会有段错误，可能由于溢出引起
}

int main()
{
    // step 2: initialize
    for (int i = 0; i < MAXN; i++)
        nodes[i].order = MAXN;

    // intput
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &nodes[addr].data, &nodes[addr].next);
        nodes[addr].addr = addr;
    }

    // step 3: purge
    int p = head, cnt = 0;
    while (p != -1)
    {
        nodes[p].order = cnt++;
        p = nodes[p].next;
    }

    // step 4: sort
    sort(nodes, nodes + MAXN, cmp);

    // step 5: output
    for (int group = 0; group < cnt / k; group++)
    {
        // 任一组的前 k - 1 个
        for (int i = k - 1; i >= 1; i--)
            printf("%05d %d %05d\n", nodes[group * k + i].addr, nodes[group * k + i].data, nodes[group * k + i -1].addr);
        // 每一组的最后一个
        if (group * k + k == cnt)  // 恰是所有元素的最后一个
            printf("%05d %d -1\n", nodes[group * k].addr, nodes[group * k].data);
        else if (group * k + k <= cnt - k)  // 还剩有完整的一组
            printf("%05d %d %05d\n", nodes[group * k].addr, nodes[group * k].data, nodes[group * k + k * 2 - 1].addr);
        else  // 是最后一个完整的一组
            printf("%05d %d %05d\n", nodes[group * k].addr, nodes[group * k].data, nodes[group * k + k].addr);
    }
    if (cnt % k != 0)
    {
        for (int i = cnt / k * k; i < cnt - 1; i++)
            printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i].next);
        printf("%05d %d -1\n", nodes[cnt - 1].addr, nodes[cnt - 1].data);
    }

    return 0;
}