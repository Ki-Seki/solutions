/*
 * hint:
 * 此题代码风格写的不好
*/

#include <iostream>
typedef long long LL;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction {
    LL num, den;
    Fraction(){}
    Fraction(LL a, LL b)
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
    Fraction operator - (const Fraction& b)
    {
        Fraction f(0, 1);
        f.num = this->num * b.den - b.num * this->den;
        f.den = this->den * b.den;
        return f;
    }
    Fraction operator * (const Fraction& b)
    {
        Fraction f;
        f.num = this->num * b.num;
        f.den = this->den * b.den;
        return f;
    }
    Fraction operator / (const Fraction& b)
    {
        Fraction f;
        f.num = this->num * b.den;
        f.den = this->den * b.num;
        return f;
    }
};

Fraction reduction(const Fraction& f)
{
    LL num = f.num, den = f.den;
    if (den == 0)
        return Fraction(1, 0);
    else if (num == 0)
        return Fraction(0, 1);
    if (den < 0)
    {
        num *= -1;
        den *= -1;
    }
    LL div = gcd(num, den);
    if (div < 0) div *= -1;
    return Fraction(num / div, den / div);
}

void output(Fraction f)
{
    f = reduction(f);
    if (f.den == 0)
        printf("Inf");
    else if (f.num == 0)
        printf("0");
    else
    {
        int sign = f.num < 0;
        if (sign) printf("(");

        if (sign && -f.num % f.den == 0 ||
            !sign && f.num % f.den == 0)
            printf("%lld", f.num / f.den);
        else if (sign && -f.num < f.den ||
                 !sign && f.num < f.den)
            printf("%lld/%lld", f.num, f.den);
        else if (sign)
            printf("%lld %lld/%lld", f.num / f.den, -f.num % f.den, f.den);
        else
            printf("%lld %lld/%lld", f.num / f.den, f.num % f.den, f.den);
        
        if (sign) printf(")");
    }
}

int main()
{
    Fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.num, &a.den, &b.num, &b.den);
    output(a); printf(" + "); output(b); printf(" = "); output(reduction(a + b)); printf("\n");
    output(a); printf(" - "); output(b); printf(" = "); output(reduction(a - b)); printf("\n");
    output(a); printf(" * "); output(b); printf(" = "); output(reduction(a * b)); printf("\n");
    output(a); printf(" / "); output(b); printf(" = "); output(reduction(a / b)); printf("\n");
    return 0;
}