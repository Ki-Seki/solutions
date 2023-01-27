#include <bits/stdc++.h>
using namespace std;

int month_days[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_valid1(int d)
{
    int year = d / 10000, month = d % 10000 / 100, day = d % 100;
    if (month > 12) return false;
    if (month==2 && ((year%400==0) || (year%4==0 && year%100!=0))) // 闰年
        if (day > 29)
            return false;
    if (day > month_days[month]) return false;
    char s[10];
    sprintf(s, "%d", d);
    if (!(s[0]==s[7] && s[1]==s[6] && s[2]==s[5] && s[3]==s[4])) return false;
    return true;
}

bool is_valid2(int d)
{
    int year = d / 10000, month = d % 10000 / 100, day = d % 100;
    if (month > 12) return false;
    if (month==2 && ((year%400==0) || (year%4==0 && year%100!=0))) // 闰年
        if (day > 29)
            return false;
    if (day > month_days[month]) return false;
    char s[10];
    sprintf(s, "%d", d);
    if (!(s[0]==s[2] && s[2]==s[5] && s[5]==s[7] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6])) return false;
    return true;
}

int main()
{
    int d;
    scanf("%d", &d);
    int state1 = 0, state2 = 0;
    int ans1, ans2;
    for (int i = d + 1; i < 100000000; i++)
    {
        if (state1 == 0 && is_valid1(i))
        {
            state1 = 1;
            ans1 = i;
        }
        if (is_valid2(i))
        {
            state2 = 1;
            ans2 = i;
        }
        if (state1==1 && state2==1) break;
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}