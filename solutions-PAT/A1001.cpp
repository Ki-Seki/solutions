#include <iostream>
using namespace std;

int main()
{
    int a, b, abs, sign;
    cin >> a >> b;
    sign = ((a + b) > 0) * 2 - 1;
    abs = sign * (a + b);
    
    if (abs <= 999) printf("%d", sign * abs);
    else if (abs <= 999999) printf("%d,%03d", sign * abs / 1000, abs % 1000);
    else printf("%d,%03d,%03d", sign * abs / 1000000, abs / 1000 % 1000, abs % 1000);
    return 0;
}