#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef unsigned long long ULL;

ULL a, b;
char c;
string line;

string reverse(ULL n)
{
    string s = "";
    while (n)
    {
        s += (n%10+'0');
        n /= 10;
    }
    return s;
}

int main()
{
    cin >> line;
    if (line.find_first_of('.') == string::npos &&
        line.find_first_of('/') == string::npos &&
        line.length() >= 19)  // 处理大于等于 19 位的数字
    {
        if (line[line.length() - 1] == '%') reverse(line.begin(), line.end()-1);
        else reverse(line.begin(), line.end());
        int i = line.find_first_not_of('0');
        for (; i < line.length(); i++) printf("%c", line[i]);
    }
    else  // 只要数字小于 19 位，均可由以下语句处理
    {
        sscanf(line.c_str(), "%lld%c%lld", &a, &c, &b);
        string s1 = reverse(a), s2 = reverse(b);
        sscanf(s1.c_str(), "%lld", &a);
        sscanf(s2.c_str(), "%lld", &b);
        printf("%lld%c", a, c);
        if (b) printf("%lld", b);
        if (c == '.' && b == 0) printf("0");
    }
    return 0;
}