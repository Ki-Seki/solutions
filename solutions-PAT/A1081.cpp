#include <iostream>

long gcd(long a, long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    long num, den;
    Fraction(long a, long b)
    {
        num = a;
        den = b;
    }
    Fraction operator + (const Fraction& b)
    {
        Fraction f(0, 1);
        f.num = this->num * b.den + b.num * this->den;
        f.den = this->den * b.den;
        return f;
    }
};

Fraction reduction(const Fraction& f)
{
    long num = f.num, den = f.den, div = gcd(num, den);
    if (f.den < 0)
    {
        num *= -1;
        den *= -1;
    }
    return Fraction(num / div, den / div);
}

int main()
{
    int n, a, b;
    Fraction sum(0, 1);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d", &a, &b);
        sum = reduction(sum + Fraction(a, b));
    }
    if (sum.num % sum.den == 0)
        printf("%d", sum.num / sum.den);
    else if (sum.num > 0 && sum.num < sum.den)
        printf("%d/%d", sum.num, sum.den);
    else if (sum.num < 0 && -sum.num < sum.den)
        printf("%d/%d", sum.num, sum.den);
    else
        printf("%d %d/%d", sum.num / sum.den, sum.num % sum.den, sum.den);
    return 0;
}