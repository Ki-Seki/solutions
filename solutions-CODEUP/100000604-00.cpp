/*
 * hint:
 * Codeup 的题一般都是测试数据有多组，输入长度未知型的题。
*/
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int a, b, c;
        a = -1000001;
        c = 1000001;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b);
            a = max(a, b);
            c = min(b, c);
        }
        printf("%d %d\n", a, c);
    }
    return 0;
}