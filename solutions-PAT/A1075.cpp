#include <iostream>
#include <algorithm>
#define MAXN 10005
#define MAXK 10
#define MAXM 100005
using namespace std;

struct Student{
    int id, score[MAXK], total, full_marks_count;
    bool toShow;

    Student()
    {
        id = MAXN;
        for (int i = 0; i < MAXK; i++) score[i] = -1;
        total = 0;
        full_marks_count = 0;
        toShow =false;
    }
} stu[MAXN];

int prob[MAXK];  // denote the full marks of problems; start from i = 1

bool cmp(Student a, Student b)
{
    if (a.total != b.total) return a.total > b.total;
    else if (a.full_marks_count != b.full_marks_count) return a.full_marks_count > b.full_marks_count;
    else return a.id < b.id;
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
        scanf("%d", &prob[i]);
    int user_id, problem_id, obtained;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &user_id, &problem_id, &obtained);

        // get every item in the Student object, stu[user_id]
        stu[user_id].id = user_id;
        if (obtained >= stu[user_id].score[problem_id])  // coverage
        {
            if (obtained == -1)  // special judge
            {
                stu[user_id].score[problem_id] = 0;
                continue;
            }
            int before = stu[user_id].score[problem_id] == -1 ? 0 : stu[user_id].score[problem_id];
            stu[user_id].total += obtained - before;
            stu[user_id].score[problem_id] = obtained;
            if (obtained == prob[problem_id] && before < prob[problem_id]) stu[user_id].full_marks_count++;
            stu[user_id].toShow = true;
        }
    }
    sort(stu + 1, stu + n + 1, cmp);  // user_id start from 1 rather than 0
    int rank = 1;
    for (int i = 1; i <= n && stu[i].toShow; i++)
    {
        // ouptut rank
        if (i > 1 && stu[i].total != stu[i-1].total)
        {
            printf("%d", i);
            rank = i;
        }
        else printf("%d", rank);

        // output id and total marks
        printf(" %05d %d", stu[i].id, stu[i].total);

        // output single marks
        for (int j = 1; j <= k; j++)
        {
            if (stu[i].score[j] == -1) printf(" -");
            else printf(" %d", stu[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}