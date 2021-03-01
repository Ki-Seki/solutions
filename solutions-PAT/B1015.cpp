#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct Student{
    int id, virtue, talent, sum, flag;
} stu[MAXN];

bool cmp(Student a, Student b)
{
    if (a.flag != b.flag) return a.flag < b.flag;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}

int main()
{
    // input and init
    int n, m = 0, l, h;
    scanf("%d%d%d", &n, &l, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &stu[i].id, &stu[i].virtue, &stu[i].talent);
        stu[i].sum = stu[i].virtue + stu[i].talent;
        if (stu[i].virtue < l || stu[i].talent < l) stu[i].flag = 5;
        else if (stu[i].virtue >= h && stu[i].talent >= h) stu[i].flag = 1;
        else if (stu[i].virtue >= h && stu[i].talent < h) stu[i].flag = 2;
        else if (stu[i].virtue < h && stu[i].talent < h && stu[i].virtue >= stu[i].talent) stu[i].flag = 3;
        else stu[i].flag = 4;
        if (stu[i].flag != 5) m++;
    }

    // sort
    sort(stu, stu + n, cmp);

    // output
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
    return 0;
}