#include <iostream>

using namespace std;

int gcd(int a, int b);
int gcd(int a, int b, int c);

int main()
{
	int a, b, c, theGCD;
	cin >> a >> b >> c;
    theGCD = gcd(a, b, c);
    a = a/theGCD;
    b = b/theGCD;
    c = c/theGCD;
	if (a<=b && a<=c)
	{
		if (b<c)
            cout << a << '/' << c;
		else
			cout << a << '/' << b;
	}
	else if (b<=a && b<=c)
	{
		if (a<c)
			cout << b << '/' << c;
		else
			cout << b << '/' << a;
	}
	else
	{
		if (a<b)
			cout << c << '/' << b;
		else
			cout << c << '/' << a;
	}
	return 0;
}

int gcd(int a, int b)
{
    if (a%b==0)
        return b;
    else
        return gcd(b, a%b);
}

int gcd(int a, int b, int c)
{
    return gcd(gcd(a, b), gcd(b,c));
}