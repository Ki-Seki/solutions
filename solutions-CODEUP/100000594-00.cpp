#include <iostream>

int exGcd(int a, int b, int&x, int&y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int gcd = exGcd(b, a%b, x, y),
            tmp = x;
        x = y;
        y = tmp - (a / b) * y;
        return gcd;
    }
}

// return the answer of ax ≡ 1(mod b)
int solve(int a, int b)
{
    int x, y, g = exGcd(a, b, x, y);
    return (x % b + b) % b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", solve(a, b));
    return 0;
}