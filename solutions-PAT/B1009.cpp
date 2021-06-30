/*
 * hint:
 * 自增、自减运算符在循环语句中慎用！尽量单独一句使用 or 用逗号运算符放置结尾
*/
#include <iostream>
#define MAXN 85
using namespace std;

int main()
{
    char words[MAXN][MAXN];
    int cnt = 0;
    while (scanf("%s", words[cnt]) != EOF)
        cnt++;
    while (cnt)
        printf(cnt-1 ? "%s " : "%s\n", words[cnt-1]), cnt--;
    return 0;
}