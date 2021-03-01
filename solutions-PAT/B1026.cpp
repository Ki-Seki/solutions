/*
 * hint:
 * 能减少浮点数操作就减少浮点数操作
*/

#include <iostream>
#define CLK_TCK 100

using namespace std;

int main()
{
    int c1, c2, interval, hh, mm, ss;
    cin >> c1 >> c2;
    interval = (c2 - c1) / 100 +
        ((c2 - c1) % CLK_TCK >= CLK_TCK / 2 ? 1 : 0);
    hh = interval / 3600;
    mm = (interval - hh * 3600) / 60;
    ss = interval % 60;
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}