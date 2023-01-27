#include <cstdio>

int a, b, c, d, e, f, i = 0, j = 0, k = 0;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}

int main()
{
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    i = a + d;
    if (b == 0 || e == 0)
    {
        j = b + e;
        k = c + f;
    }
    else
    {
        int g = gcd(c, f);
        j = b * f / g + e * c / g;
        k = c * f / g;
        g = gcd(j, k);
        j /= g;
        k /= g;
    }
    if (j == 0)
    {
        printf("%d 0 0", i);
    }
    else
    {
        if (j == k)
        {
            i++;
            j = 0;
            k = 0;
        }
        else if (j > k)
        {
            i += j / k;
            j %= k;
        }
        printf("%d %d %d", i, j, k);
    }
    return 0; 
}