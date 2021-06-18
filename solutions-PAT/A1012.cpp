/*
 * hint:
 * C++ 中“不明确”错误的出现，多是因为定义的变量符号与 std 命名空间中的变量名冲突了
*/
#include <iostream>
#include <algorithm>
#define MAXN 2005
#define MAXID 1000000

struct Student {
    int id,
    grade[4];  // grade consists of a, c, m, e
} stu[MAXN];
int rank[MAXID][4] = {};  // to make the query easier
char mp[4] = {'A', 'C', 'M', 'E'};

int now;  // assistant variable for cmp()
bool cmp(Student a, Student b)
{
    return (a.grade[now] > b.grade[now]);
}

int main()
{
    // input the info.
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
    }

    // sort and calculate the ranks
    for (now = 0; now < 4; now++)
    {
        std::sort(stu, stu + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (stu[i].grade[now] == stu[i-1].grade[now])
                rank[stu[i].id][now] = rank[stu[i-1].id][now];
            else
                rank[stu[i].id][now] = i + 1;
        }
    }

    // input queries and output the results
    int query;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &query);
        if (rank[query][0] == 0)
            printf("N/A\n");
        else
        {
            int best = 0;  // the highest score's index
            for (int j = 1; j < 4; j++)
                if (rank[query][j] < rank[query][best])
                    best = j;
            printf("%d %c\n", rank[query][best], mp[best]);
        }
    }
    return 0;
}