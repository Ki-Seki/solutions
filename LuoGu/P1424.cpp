#include <iostream>

using namespace std;

int main()
{
    int x, n, total=0;
    cin >> x >> n;
    for(int i=x;i<x+n;i++)
    {
        if (i%7==0 || i%7==6)
            continue;
        else
            total += 250;
        
    }
    cout << total;
    return 0;
}