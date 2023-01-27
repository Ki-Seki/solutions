#include <iostream>

struct Fraction {
    int num, den;

    Fraction() {}
    Fraction(int a, int b)
    {
        this->num = a;
        this->den = b;
    }
};

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

Fraction reduction(const Fraction& f)
{
    int d = gcd(f.num, f.den);
    return Fraction(f.num / d, f.den / d);
}

Fraction operator + (const Fraction& a, const Fraction& b)
{
    Fraction ans;
    ans.num = a.num * b.den + b.num * a.den;
    ans.den = a.den * b.den;
    return reduction(ans);
}

double cal_matrix(int n)
{
    double ans = n;
    for (int i = 2; i <= n; i++)
        ans += 2.0 * (n + 1 -i) / i;
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
        printf("%.2lf\n", cal_matrix(n));
}