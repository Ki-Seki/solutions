/*
 * hint:
 * 未解决
*/
#include <bits/stdc++.h>
using namespace std;

set<int> weight;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        set<int> tmp_set;
        scanf("%d", &tmp);
        for (set<int>::iterator it = weight.begin(); it != weight.end(); it++)
        {
            tmp_set.insert((*it) + tmp);
            tmp_set.insert((*it) - tmp);
        }
        for (set<int>::iterator it = tmp_set.begin(); it != tmp_set.end(); it++)
            weight.insert(*it);
        weight.insert(tmp);
        weight.insert(-tmp);
    }
    int cnt = 0;
    for (set<int>::iterator it = weight.begin(); it != weight.end(); it++)
        if (*it > 0)
            cnt++;
    printf("%d", cnt);
    return 0;
}