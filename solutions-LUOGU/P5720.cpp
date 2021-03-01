#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, day = 1;
    cin >> a;
    while (true)
    {
        if (a<=1)
        {
            break;
        }
        else
        {
            a /= 2;
            day++;
        }
    }
    cout << day;
    return 0;
}
