#include <iostream>
using namespace std;

int main()
{
    char mp[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int a, b, c;
    cin >> a >> b >> c;
    printf("#%c%c%c%c%c%c\n", mp[a/13], mp[a%13], mp[b/13], mp[b%13], mp[c/13], mp[c%13]);
    return 0;
}