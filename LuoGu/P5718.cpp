#include <iostream>

using namespace std;

int main()
{
    int n, a, min=100000;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(a < min) min = a;
    }
    cout << min;
    return 0;
}