/*
 * hint:
 * 测试点1，测试点2：考察对排序后 stu[MAXN] 的 i（下标）和id（属性）的区别的认知程度
*/
#include <iostream>
#include <algorithm>
#define MAXN 40005
#define MAXM 105
#define MAXK 10
using namespace std;

struct Student {
    int ge, gi, final, rank, id, preference[MAXK];
} stu[MAXN];

struct School {
    int quota, cnt_received, index_received[MAXN], index_last_received;
    School ()
    {
        cnt_received = 0;
        index_last_received = -1;
    }
} sch[MAXM];

bool cmp_student(Student a, Student b)
{
    if (a.final != b.final) return a.final > b.final;
    else return a.ge > b.ge;
}

bool cmp_id(int a, int b)
{
    return stu[a].id < stu[b].id;
}

int main()
{
    // input
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        scanf("%d", &sch[i].quota);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].final = stu[i].ge + stu[i].gi;
        stu[i].id = i;
        for (int j = 0; j < k; j++)
            scanf("%d", &stu[i].preference[j]);
    }

    // sort
    sort(stu, stu + n, cmp_student);

    // get ranks
    for (int i = 0; i < n; i++)
        if (i > 0 && stu[i].final == stu[i-1].final && stu[i].ge == stu[i-1].ge)
            stu[i].rank = stu[i-1].rank;
        else
            stu[i].rank = i + 1;
    
    // simulate admission
    for (int i = 0; i < n; i++)
    {
        // search proper school for stu[i]
        int choice = 0, id_target_school, rcv_window, index_last_received, rank_last_received;
        for (; choice < k; choice++)
        {
            id_target_school = stu[i].preference[choice];
            rcv_window = sch[id_target_school].quota - sch[id_target_school].cnt_received;
            index_last_received = sch[id_target_school].index_last_received;
            rank_last_received = stu[sch[id_target_school].index_last_received].rank;
            if (rcv_window > 0) break;
            else if (index_last_received != -1 && rank_last_received == stu[i].rank) break;
        }
        
        // test
        // printf("\nstu:%d -> sch:%d\n", i, id_target_school);

        // sch[id_target_scholl] admit stu[i]
        if (choice < k)
        {
            int cnt = sch[id_target_school].cnt_received++;
            sch[id_target_school].index_received[cnt] = i;
            sch[id_target_school].index_last_received = i;
        }
    }

    // output
    for (int i = 0; i < m; i++)
    {
        if (sch[i].index_last_received != -1)
        {
            sort(sch[i].index_received, sch[i].index_received + sch[i].cnt_received, cmp_id);
            for (int j = 0; j < sch[i].cnt_received; j++)
                printf(j == sch[i].cnt_received - 1 ? "%d" : "%d ", stu[sch[i].index_received[j]].id);
        }
        printf("\n");
    }
    return 0;
}