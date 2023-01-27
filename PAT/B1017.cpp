#include <iostream>
#include <cstring>
#define MAXN 1000

char sa[MAXN];
int b,
    r = 0;  // remainder

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

BigInteger operator / (BigInteger a, int b)
{
    BigInteger quot;
    quot.len = a.len;
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.digits[i];
        quot.digits[i] = r / b;
        r = r % b;
    }
    if (quot.len > 1 && quot.digits[quot.len - 1] == 0) quot.len--;
    return quot;
}

void output(BigInteger n)
{
    for (int i = n.len - 1; i >= 0; i--)
        printf("%d", n.digits[i]);
}

int main()
{
    scanf("%s %d", sa, &b);
    output(s2i(sa) / b);
    printf(" %d", r);
}