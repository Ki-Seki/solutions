/*
 * 本题不需要模拟，将 # 符号视作出栈符号，其他字母均是入栈标志即可
 * 简单证明如下（配合图示将更加清楚）：
 * 仅靠先序序列所唯一确定的二叉树只能是不分叉的二叉树，也就是数的度一定是 1
 * 因此对于第一个节点，一定是根节点，
 * 若下个节点是 #，则意味着节点向右分叉，则直接输出这个节点即可；
 * 若下个节点是字母，则意味着节点有左节点，左节点在中序序列中是在中间节点输出后才输出的，所以先入栈，
 * 待下个 # 出现时，就找到了根节点，根据随后的 # 量逐渐 pop 即可
*/
#include <cstdio>
#include <stack>
#include <cstring>
#define MAXLEN 105

using namespace std;

char s[MAXLEN];

int main()
{
    while (scanf("%s", s) != EOF)  // EOF 意味着读完了
    {
        int len = strlen(s);
        stack<char> stk;
        for (int i = 0; i < len; i++)
            if (s[i] != '#')
                stk.push(s[i]);
            else if (!stk.empty())
                printf("%c ", stk.top()), stk.pop();
        while (!stk.empty())
            printf("%c ", stk.top()), stk.pop();
        printf("\n");
    }
    return 0;
}