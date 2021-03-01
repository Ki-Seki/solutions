/*
 * hint:
 * 对于没有提示的输入，可以利用
 * while (scanf("%d%d", &coe, &exp) != EOF)，scanf 返回正确接受输入的个数，遇到文件尾时返回 EOF
 * 或者 while (cin >> coe >> exp)，cin 返回 istream& 类型的 cin 自身，遇到文件尾时返回 0
*/

#include <iostream>
using namespace std;

int main()
{
    int coe, exp;
    bool no_output = true;
    while (scanf("%d%d", &coe, &exp) != EOF)
    {
        if (exp)
        {
            printf(no_output ? "%d %d" : " %d %d", coe * exp, exp - 1);
            no_output = false;
        }
    }
    if (no_output) printf("0 0");
    return 0;
}