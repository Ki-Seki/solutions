#include <iostream>
using namespace std;

int candy(int cnt)
{
    if (cnt == 1)
        return 1;
    else if (cnt == 2)
        return 2;
    else
        return candy(cnt - 1) + candy(cnt - 2);
}

int main()
{
    int n;
    while (cin >> n)
        cout << candy(n) << endl;
    return 0;
}