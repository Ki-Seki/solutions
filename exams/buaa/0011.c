#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        int round = 0, tmp, ta, tb;
        while (a != 0 && b != 0)
        {
            round++;
            // 保证 a > b
            if (a < b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }
            // 临时变量
            ta = a;
            tb = b;
            // 尝试直接胜利
            if (ta % tb == 0) break;
            // 尝试减去最大
            ta = ta % tb;
            if (tb % ta != 0)
            {
                a = tb;
                b = ta;
                continue;
            }
            a = a - b;
        }
        printf(round%2 ? "Nova\n" : "LaoWang\n");
    }
    return 0;
}