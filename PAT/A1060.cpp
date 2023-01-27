/*
 * hint:
 * 
 * 本体使用状态机求解。
 * 由于是字符串处理的问题，状态机求解则会十分高效。
 * 思路同样是 定义任务 -> 定义状态 -> 执行响应状态的行为并转移状态
 * 
 * 任务：去除所有不在有效数位内部的 0，并计算出 exp
 * 状态：（最后一列是一种表达唯一状态的一种方法）
 * * status_code 1: 初始状态               $
 * * status_code 2: 初始时读入点           $ -> not '0' & '.'
 * * status_code 3: 初始时读入非点非零      $ -> not '0' & '.'
 * * status_code 4: 初始时读入点后读的零    $ -> '.' -> '0' or '0's
 * * status_code 0: 结束状态
 * 
 * ps.
 * 本题可以在空间复杂度上继续优化，即从终端一个字符一个字符读取，而不是读入字符串；
 * 但这样算法逻辑上会稍复杂。
*/

#include <iostream>
#include <string>

using namespace std;

struct SciNum
{
    string sig;
    int exp;
};

string n_zero(int n)
{
    string s;
    while (n--) s += '0';
    return s;
}

SciNum fsm(string s, int w)
{
    // indicate a substr
    int begin = 0, end = s.length();

    //clear pre- and post- zeros
    while (s[begin] == '0') begin++;
    if (s.find('.') != string::npos)
        while (s[end - 1] == '0') end--;
    
    // special judge: if the number is 0
    if (end == begin || (end - begin == 1 && s[begin] == '.'))
    {
        SciNum ans;
        ans.exp = 0;
        ans.sig = n_zero(w);
        return ans;
    }

    // fsm: find significants and the dot_pos within the significants
    int status_code = 1, p = begin, dot_pos;
    while (status_code)
        switch (status_code)
        {
        case 1:  // initialized status: $
            if (s[p] == '.') status_code = 2;
            else status_code = 3;
            break;
        case 2:  // $ -> '.'
            dot_pos = p - begin;
            begin++;  // erease '.'
            p++;
            if (s[p] == '0') status_code = 4;
            else status_code = 0;
            break;
        case 3:  // $ -> not '0' & '.'
            if (s.find('.') != string::npos)
                {
                    dot_pos = s.find('.') - begin;
                    s.erase(s.find('.'), 1);  // erase '.'
                    end--;
                }
            else
                dot_pos = end - begin;
            status_code = 0;
            break;
        case 4:  // $ -> '.' -> '0' or '0's
            dot_pos--;
            begin++;
            p++;
            if (s[p] == '0') status_code = 4;
            else status_code = 0;
            break;
        }

    // return ans
    SciNum ans;
    if (end - begin >= w)
    {
        ans.sig = s.substr(begin, w);
        ans.exp = dot_pos;
    }
    else
    {
        ans.sig = s.substr(begin, end - begin) + n_zero(w - (end - begin));
        ans.exp = dot_pos;
    }
    return ans;
}

ostream& operator << (ostream& out, const SciNum& s)
{
    return out << "0." << s.sig << "*10^" << s.exp;
}

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    SciNum sa = fsm(a, n), sb = fsm(b, n);
    if (sa.sig == sb.sig && sa.exp == sb.exp)
        cout << "YES " << sa;
    else
        cout << "NO " << sa << ' ' << sb; 
    return 0;
}