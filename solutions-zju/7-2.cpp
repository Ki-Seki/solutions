#include <iostream>
using namespace std;

struct Fraction {
    int num, den;
} a, b, c, d;

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}

Fraction operator + (Fraction a, Fraction b)
{
    Fraction result;
    if (a.num == 0)
    {
        result.num = b.num;
        result.den = b.den;
    }
    else if (b.num == 0)
    {
        result.num = a.num;
        result.den = a.den;
    }
    else
    {
        int g = gcd(a.den, b.den);
        result.num = a.num * b.den / g + b.num * a.den / g;
        result.den = a.den * b.den / g;
    }
    return result;
}

int main()
{
    cin >> a.num >> a.den >> b.num >> b.den >> d.num >> d.den;
    b.num *= -1;
    Fraction ans = a + d + b;  // 相当于 a+d-b
    int g = gcd(ans.num, ans.den);
    printf("%d %d", ans.num/g, ans.den/g);
    return 0;
}