#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	double a, b, c, p, s;
	cin >> a >> b >> c;
	p = 0.5*(a+b+c);
	s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1f", s);
	return 0;
}

