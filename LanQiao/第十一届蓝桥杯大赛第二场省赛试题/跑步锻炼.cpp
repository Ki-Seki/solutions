#include<cstdio>

struct Date {
    int y, m, d;
};

int days_of_a_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 使用基姆拉尔森公式，用于转换日期到星期
int kim_larson(int y, int m, int d)
{
    if (m < 3)
    {
        m += 12;
        y--;
    }
    return (1 + d + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400) % 7;
}

bool is_leap(int y)
{
    if (y % 400 == 0) return true;
    else if (y % 100 == 0) return false;
    else if (y % 4 == 0) return true;
    else return false;
}

bool operator <=(const Date a, const Date b)
{
    int arra = a.y * 10000 + a.m * 100 + a.d,
        arrb = b.y * 10000 + b.m * 100 + b.d;
    return arra <= arrb;
}

Date operator +(Date a, int b)
{
    int days = days_of_a_month[a.m - 1];
    if (a.m == 2 && is_leap(a.y)) days = 29;
    a.d += b;
    a.m += (a.d - 1) / days;
    a.y += (a.m - 1) / 12;
    if (a.d > days) a.d %= days;
    if (a.m > 12) a.m %= 12;
    return a;
}

int main()
{
    long long ans = 0;
    Date start = {2000, 1, 1}, end = {2020, 10, 1};
    //scanf("%d %d %d", &end.y, &end.m, &end.d);
    while (start <= end)
    {
        if (start.d == 1 || kim_larson(start.y, start.m, start.d) == 1)
            ans += 2;
        else
            ans++;
        start = start + 1;
    }
    printf("%lld", ans);
    return 0;
}
