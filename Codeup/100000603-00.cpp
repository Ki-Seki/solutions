#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            pair<double, double> a, b, c;
            scanf("%lf %lf %lf %lf %lf %lf", &a.first, &a.second, &b.first, &b.second, &c.first, &c.second);
            printf("%.1lf %.1lf\n", (a.first + b.first + c.first) / 3, (a.second + b.second + c.second) / 3);
        }
    }
    return 0;
}