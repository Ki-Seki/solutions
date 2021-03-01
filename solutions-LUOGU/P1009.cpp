#include <iostream>

using namespace std;

int main()
{
    // long long int n;
    for(int n=1; n<=50; n++)
    {
        long long int res = 1;
        for(int j=1; j<=n; j++)
        {
            res *= j;
        }
        cout << res << ", ";
    }
    return 0;
}