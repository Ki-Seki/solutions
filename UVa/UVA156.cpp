#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

string repr(string s)
{
    for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
    sort(s.begin(), s.end());
    return s;
}

int main()
{
    map<string, int> anan;
    vector<string> tot, ans;
    string tmp;
    while (cin >> tmp)
    {
        if (tmp == "#") break;
        tot.push_back(tmp);
        string repr_tmp = repr(tmp);
        if (!anan[repr_tmp]) anan[repr_tmp] = 1;
        else anan[repr_tmp]++;
    }
    for (int i = 0; i < tot.size(); i++)
    {
        if (anan[repr(tot[i])] == 1) ans.push_back(tot[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    
    return 0;
}