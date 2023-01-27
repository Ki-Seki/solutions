#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxcol = 60;
const int maxn = 100 + 5;
string filenames[maxn];

// 实现字符串补齐功能
void print(const string& s, int len, char extra)
{
    cout << s;
    for (int i = 0; i < len - s.length(); i++) cout << extra;
}

int main()
{
    int n;
    while (cin >> n)
    {
        // 计算 M，同时输入数据
        int M = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> filenames[i];
            M = max(M, (int)filenames[i].length());  // STL 的模板 max 函数
        }

        // 计算 cols，rows
        int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
        print("", 60, '-');
        cout << endl;

        // 排序
        sort(filenames, filenames + n);  // STL
        
        // 输出
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int idx = c * rows + r;
                if (idx < n) print(filenames[idx], c == cols-1 ? M : M+2, ' ');
            }
            cout << endl;
        }
    }
    return 0;
}