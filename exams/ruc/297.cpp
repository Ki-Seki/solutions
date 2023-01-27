#include <bits/stdc++.h>
using namespace std;

string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main()
{
    int d1, d2;
    scanf("%d %d", &d1, &d2);
    cout << day[(d1)%7] << endl
         << day[(d2+7-2)%7] << endl;
    return 0;
}