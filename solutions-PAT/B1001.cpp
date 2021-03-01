#include <iostream>

using namespace std;

int main()
{
    int n, steps = 0;
    cin >> n;
    while(n > 1)
    {
        if (n % 2)
        {
            n = (3 * n + 1) / 2;
        }
        else
        {
            n /= 2;
        }
        steps++;
    }
    cout << steps;
    return 0;
}