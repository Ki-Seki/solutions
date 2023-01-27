/*
 * hint:
 * 
 * 本体并没有按常规解法来做。
 * 而是将求解中缀表达式和计算结果两个过程融合在一起来进行了。
*/
#include <stack>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<char, int> sign_priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

int main()
{
    while (true)
    {
        string line;
        getline(cin, line);
        if (line.length() == 1 && line[0] == '0') break;

        stack<char> sign;
        stack<double> ans;

        // parse a line
        for (int i = 0; i < line.length(); i++)
        {
            if ('0' <= line[i] && line[i] <= '9')
            {
                int num = 0;
                while (i < line.length() && '0' <= line[i] && line[i] <= '9')
                    num = num * 10 + line[i++] - '0';
                ans.push(num);
            }
            if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
            {
                if (sign.empty())
                    sign.push(line[i]);
                else if (sign_priority[line[i]] <= sign_priority[sign.top()])
                {
                    double b = ans.top(); ans.pop();
                    double a = ans.top(); ans.pop();
                    if (sign.top() == '+') ans.push(a + b);
                    if (sign.top() == '-') ans.push(a - b);
                    if (sign.top() == '*') ans.push(a * b);
                    if (sign.top() == '/') ans.push(a / b);
                    sign.pop();
                    i--;
                }
                else
                    sign.push(line[i]);
            }
        }
        while (!sign.empty())
        {
            double b = ans.top(); ans.pop();
            double a = ans.top(); ans.pop();
            if (sign.top() == '+') ans.push(a + b);
            if (sign.top() == '-') ans.push(a - b);
            if (sign.top() == '*') ans.push(a * b);
            if (sign.top() == '/') ans.push(a / b);
            sign.pop();
        }
        printf("%.2lf\n", ans.top());
    }
    return 0;
}