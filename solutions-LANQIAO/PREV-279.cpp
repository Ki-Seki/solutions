#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL n;
    cin >> n;
    n /= 1000;
    n %= 86400;
    int h = n / 3600, 
        m = (n - h * 3600) / 60,
        s = n % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}