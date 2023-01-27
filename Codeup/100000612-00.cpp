#include<cstdio>
#include<cmath>
#define MAXN 1005

int n, d;
char buffer[MAXN * 100];

int main()
{
    while (scanf("%d\n", &n) && n != 0)
    {
        gets(buffer);
        scanf("%d", &d);
        int f1 = pow(2, d - 1) - 1,  // 深度为 (d - 1) 的满二叉树（中国概念，下同）所拥有的节点数
            f2 = pow(2, d) - 1;  // 深度为 d 的满二叉树（中国概念，下同）所拥有的节点数
        if (f1 > n)
            printf("EMPTY\n");
        else
        {
            int start = pow(2, d - 1),
                end = f2 <= n ? pow(2, d) - 1 : n;
            for (int i = start; i <= end; i++)
                printf(i == end ? "%d\n" : "%d ", i);
        }
    }
    return 0;
}