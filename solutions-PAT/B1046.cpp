#include <iostream>

using namespace std;

int main()
{
    int a1, a2, b1, b2, round, afail = 0, bfail = 0;
    cin >> round;
    for (int i = 0; i < round; i++)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        int sum = a1 + b1;
        if ((a2 == sum) && (b2 != sum)) bfail++;
        if ((a2 != sum) && (b2 == sum)) afail++;
    }
    cout << afail << ' ' << bfail;
    return 0;
}