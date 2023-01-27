/*
 * hint:
 * 典型的高精度题，要掌握：
 * 高精度数 × int 和
 * 高精度数 + int
 * 这两个一旦掌握，高精度题就迎刃而解了
*/

#include <bits/stdc++.h>
#define MAXBITS 100
using namespace std;

int n, a[MAXBITS+1] = {0}, s[MAXBITS+1] = {0};

void multiply(int x)
{
    int carry = 0;  // 进位
    for (int i = MAXBITS; i >= 0; i--)
    {
        a[i] = a[i] * x + carry;
        carry = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

// s += a
void sum()
{
    int carry = 0;
    for (int i = MAXBITS; i >= 0; i--)
    {
        s[i] = s[i] + a[i] + carry;
        carry = s[i] / 10;
        s[i] = s[i] % 10;
    }
}

void output()
{
    int w;

    // 找到开始的位数
    for (int i = 0; i <= MAXBITS; i++)
    {
        if (s[i])
        {
            w = i;
            break;
        }
    }

    // 输出
    for (int i = w; i <= MAXBITS; i++)
        printf("%d", s[i]);
}

int main()
{
    scanf("%d", &n);
    s[MAXBITS] = a[MAXBITS] = 1;
    for (int i = 2; i <= n; i++)
    {
        multiply(i);
        sum();
    }
    output();
    return 0;
}