#include <cstdio>
#include <cstring>
#define MAXN 4500
char n1[MAXN], n2[MAXN];
int a[MAXN], b[MAXN], c[MAXN];  // mutiple1, multiple2, carry (answer)

int main()
{
    scanf("%s%s", n1, n2);
    int l1 =strlen(n1), l2 = strlen(n2);
    for (int i = 1; i <= l1; i++) a[i] = n1[l1-i]-'0';
    for (int i = 1; i <= l2; i++) b[i] = n2[l2-i]-'0';
    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++)
            c[i+j-1] += a[i] * b[j];
    int len = l1 + l2 + 1;
    for (int i = 1; i <= len; i++)
        if (c[i] > 9)
        {
            c[i+1] = c[i+1] + c[i] / 10;
            c[i] %= 10;
        }
    while (c[len]==0 && len>1)len--;
    for (int i=len; i>=1; i--) printf("%d", c[i]);
    return 0;
}