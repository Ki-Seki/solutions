/*
 * hint:
 * * 未解决
*/

#include<bits/stdc++.h>
#define MAXN 109

using namespace std;

int arr[MAXN];
int n, m, p, q;

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        if (p == 0) sort(arr+1, arr+q+1, cmp);
        else sort(arr+q, arr+n+1);
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    return 0;
}