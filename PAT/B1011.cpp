#include <iostream>

using namespace std;

int main()
{
    int T;
    long long a, b, c;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {
        cin >> a >> b >>c;
        printf("Case #%d: %s\n", kase, (a+b>c?"true":"false"));
    }
    return 0;
}