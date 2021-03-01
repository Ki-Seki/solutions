#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Student {
    char id[15];
    int grade, local_rank, loc;
} stu[100 * 300 + 5];

bool cmp(Student a, Student b)
{
    if (a.grade != b.grade) return a.grade > b.grade;
    else return strcmp(a.id, b.id) < 0;
}

int main()
{
    int n, k, cnt = 0;
    cin >> n;
    for (int loc = 1; loc <= n; loc++)
    {
        // readin k students info
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%s %d", stu[cnt].id, &stu[cnt].grade);
            stu[cnt].loc = loc;
            cnt++;
        }

        // partially sort
        sort(stu + cnt - k, stu + cnt, cmp);

        // calculate local ranks
        stu[cnt - k].local_rank = 1;
        for (int i = cnt - k + 1; i < cnt; i++)
            if (stu[i].grade == stu[i-1].grade)
                stu[i].local_rank = stu[i-1].local_rank;
            else
                stu[i].local_rank = i - (cnt - k) + 1;
    }
    sort(stu, stu + cnt, cmp);

    // output
    cout << cnt << endl;
    printf("%s %d %d %d\n", stu[0].id, 1, stu[0].loc, stu[0].local_rank);
    int lst_rank = 1;
    for (int i = 1; i < cnt; i++)
        if (stu[i].grade == stu[i-1].grade)
            printf("%s %d %d %d\n", stu[i].id, lst_rank, stu[i].loc, stu[i].local_rank);
        else
        {
            printf("%s %d %d %d\n", stu[i].id, i + 1, stu[i].loc, stu[i].local_rank);
            lst_rank = i + 1;
        }
    return 0;
}