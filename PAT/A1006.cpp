/*
 * hint:
 * 1. C风格字符串变量相互间的赋值要用memcpy，memcpy 在 C 的 <string.h> 库中
 * 2. 时间 日期 都可以用归一化的比较方式
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Info{
    char id[20];
    int time; // time = hh * 10000 + mm * 100 + ss;
} earlist={"", 240000}, oldest={"", 0};

int main()
{
    char id[20];
    int m, h1, m1, s1, h2, m2, s2, time1, time2;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", id, &h1, &m1, &s1, &h2, &m2, &s2);
        time1 = h1 * 10000 + m1 *100 + s1;
        time2 = h2 * 10000 + m2 *100 + s2;
        if (time1 <= earlist.time) { memcpy(earlist.id, id, sizeof(id)); earlist.time = time1;}
        if (time2 >= oldest.time) { memcpy(oldest.id, id, sizeof(id)); oldest.time = time2;}
    }
    printf("%s %s\n", earlist.id, oldest.id);
    return 0;
}