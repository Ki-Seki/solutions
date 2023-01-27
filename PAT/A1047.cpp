#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 40000
#define MAXK 2500
using namespace std;

char names[MAXN + 5][5];
vector<int> cou_stu[MAXK + 5];  // course - student table

int cmp_names(char name1[], char name2[])
{
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++)
    {
        id1 = id1 * 26 + name1[i];
        id2 = id2 * 26 + name2[i];
    }
    id1 = id1 * 10 + name1[3];
    id2 = id2 * 10 + name2[3];
    return id1 - id2;
}

int cmp_id(int i, int j)
{
    return cmp_names(names[i], names[j]) < 0;
}

int main()
{
    // input
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int c;
        scanf("%s %d", names[i], &c);
        for (int j = 0; j < c; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            cou_stu[tmp].push_back(i);
        }
    }

    // sort + output
    for (int i = 1; i <= k; i++)
    {
        int stu_cnt = cou_stu[i].size();
        printf("%d %d\n", i, stu_cnt);
        sort(cou_stu[i].begin(), cou_stu[i].end(), cmp_id);
        for (int j = 0; j < stu_cnt; j++)
            printf("%s\n", names[cou_stu[i][j]]);
    }
    return 0;
}