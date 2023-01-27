/*
 * hint:
 * 正溢出，和非正；负溢出，和非负
*/

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long a, b, c, res;
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a + b;
        bool ans;
        if (a > 0 && b > 0 && res <= 0) ans = true;
        else if (a < 0 && b < 0 && res >= 0) ans = false;
        else if (res > c) ans = true;
        else ans = false;
        printf(ans ? "Case #%d: true\n" : "Case #%d: false\n", i);
    }
    return 0;
}