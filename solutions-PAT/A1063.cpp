#include <cstdio>
#include <algorithm>
#include <set>
#define MAXN 50
using namespace std;

set<int> sets[MAXN + 5];

double get_similarity(int a, int b)
{
    int intersection = 0;
    if (sets[a].size() > sets[b].size()) swap(a, b);
    for (set<int>::iterator it = sets[a].begin(); it != sets[a].end(); it++)
        if (sets[b].find(*(it)) != sets[b].end()) intersection++;
    return 100.0 * intersection / (sets[a].size() + sets[b].size() - intersection);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int cnt, val;
        scanf("%d", &cnt);
        for (; cnt > 0; cnt--)
        {
            scanf("%d", &val);
            sets[i].insert(val);
        }
    }
    int queries;
    scanf("%d", &queries);
    for (int i = 0; i < queries; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%.1lf%\n", get_similarity(a, b));
    }
    return 0;
}