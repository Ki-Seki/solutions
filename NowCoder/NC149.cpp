// 通过 5/7 组用例

#include <iostream>
#include <string>
using namespace std;

// find count of S in T
int kmp(string S, string T)
{
    if (S.empty() || S.size() > T.size())
        return 0;

    // 计算 next 数组
    int i = 1, j = 0, next[500005];
    next[1] = 0;
    while (i <= S.length())
    {
        if (j == 0 || T[i - 1] == S[j - 1])
        {
            i++;
            j++;
            // if (T[i - 1] != S[j - 1])
                next[i] = j;
            // else
            //     next[i] = next[j];
        }
        else
            j = next[j];
    }

    // 计算T中S出现多少次
    i = 1, j = 1;
    int cnt = 0;
    while (i <= T.length())
    {
        if (j == 0 || T[i - 1] == S[j - 1])
        {
            i++;
            j++;
        }
        else
            j = next[j];
        if (j >= S.length())
        {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}

int main ()
{
    string s = "ababab", t = "ababababab";
    cout << kmp(s, t);
    return 0;
}