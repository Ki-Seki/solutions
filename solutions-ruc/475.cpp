#include <bits/stdc++.h>
using namespace std;

int a1[22], a2[22], i1=0, i2=0;

int main()
{
    while (scanf("%d", &a1[i1])!=EOF && a1[i1]!=-1) i1++;
    while (scanf("%d", &a2[i2])!=EOF && a2[i2]!=-1) i2++;
    cout << i1 << endl << i2 << endl;
    for (int a=0, b=0; a < i1 && b < i2; a++, b++)
    {
        if (a1[a] != a2[b])
        {
            cout << a1[a] - a2[b] << endl;
            return 0;
        }
    }
    if (i1 == i2) cout << 0 << endl;
    else cout << "Not Comparable\n";
    return 0;
}