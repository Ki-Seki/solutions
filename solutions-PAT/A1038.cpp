#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 10005
using namespace std;

string number[MAXN];

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n, cmp);
    bool time_to_output = false;
    for (int i = 0; i < n; i++)
    {
        int len = number[i].length();
        for (int j = 0; j < len; j++)
            if (time_to_output)
                cout << number[i][j];
            else if (! time_to_output && number[i][j] != '0')
            {
                time_to_output = true;
                cout << number[i][j];
            }
    }
    if (! time_to_output) cout << '0';
    return 0;
}