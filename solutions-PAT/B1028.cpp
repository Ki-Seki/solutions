#include <iostream>
#define MAXC 6
#define LEFT 18140906
#define RIGHT 20140906
using namespace std;

struct {
    char name[MAXC];
    int year, month, day, id; // id = year*10000 + month*100 + day
} youngest={"", 1814, 9, 6, 18140906}, oldest={"", 2014, 9, 6, 20140906}, tmp;

int main()
{
    int n, left, right, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.day);
        tmp.id = tmp.year*10000 + tmp.month*100 + tmp.day;
        if (tmp.id <= RIGHT && tmp.id >= LEFT)
        {
            count++;
            if (tmp.id >= youngest.id) youngest = tmp;
            if (tmp.id <= oldest.id) oldest =tmp;
        }
    }
    printf(count ? "%d %s %s" : "%d", count, oldest.name, youngest.name);  // if no llegal output, only print 0
    return 0;
}