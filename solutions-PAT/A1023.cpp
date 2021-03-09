/*
 * hint:
 * 测试点 2，7：考察大整数乘以整型数时，有没有处理好最后一个进位。998 * 2 = 1998（而不是 998）
*/

#include <iostream>
#include <cstring>
#define MAXN 25

struct BigInteger
{
    int digits[MAXN], len;

    BigInteger()
    {
        memset(digits, 0, sizeof(digits));
        len = 0;
    }
};

BigInteger s2i(char str[])
{
    BigInteger n;
    int len = strlen(str);
    n.len = len;
    for (int i = 0; i < len; i++)
        n.digits[i] = str[len - i - 1] - '0';
    return n;
}

BigInteger operator * (BigInteger a, int b)
{
    BigInteger prod;
    int carry = 0;
    for (int i = 0; i < a.len; i++)
    {
        carry += a.digits[i] * b;
        prod.digits[prod.len++] = carry % 10;
        carry /= 10;
    }
    if (carry != 0) prod.digits[prod.len++] = carry;
    return prod;
}

bool is_consist(BigInteger a, BigInteger b)
{
    int zero_2_nine[10];
    memset(zero_2_nine, 0, sizeof(zero_2_nine));
    for (int i = 0; i < a.len; i++)
        zero_2_nine[a.digits[i]]++;
    for (int i = 0; i < b.len; i++)
        zero_2_nine[b.digits[i]]--;
    for (int i = 0; i < 10; i++)
        if (zero_2_nine[i] != 0)
            return false;
    return true;
}

void output(BigInteger n)
{
    for (int i = n.len - 1; i >= 0; i--)
        printf("%d", n.digits[i]);
}

int main()
{
    char s[MAXN];
    scanf("%s", s);
    BigInteger n = s2i(s), n2 = n * 2;
    printf(is_consist(n, n2) ? "Yes\n": "No\n");
    output(n2);
    return 0;
}