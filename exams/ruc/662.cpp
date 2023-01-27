#include <bits/stdc++.h>
using namespace std;

string name;
int final, compre;
char l, w;
bool is_leader, is_west;
int paper;
int scholarship = 0;

int main()
{
    cin >> name >> final >> compre >> l >> w >> paper;
    is_leader = (l == 'Y');
    is_west = (w == 'Y');
    if (final > 80 && paper >= 1) scholarship += 6000;
    if (final > 85 && compre > 80) scholarship += 5000;
    if (final > 90) scholarship += 4000;
    if (final > 85 && is_west) scholarship += 2500;
    if (compre > 80 && is_leader) scholarship += 950;
    cout << name << ' ' << scholarship << endl;
    return 0;
}