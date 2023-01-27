#include <bits/stdc++.h>
using namespace std;

int n, m, tmp;
long long sum1=0, sum2=0;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp % m == 0) sum1 += tmp;
        else sum2 += tmp;
    }
    if (sum1) cout << sum1 << endl;
    if (sum2) cout << sum2 << endl;
    return 0;
}