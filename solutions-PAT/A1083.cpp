#include <iostream>
#include <algorithm>
#define MAXN 55
using namespace std;

struct Student{
    char name[15], id[15];
    int grade;
} stu[MAXN];

bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n, l, r;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    sort(stu, stu + n, cmp);
    cin >> l >> r;
    bool hasOutput = false;
    for (int i = 0; i < n; i++)
    {
        if (l <= stu[i].grade && stu[i].grade <= r)
        {
            hasOutput = true;
            printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    if (!hasOutput) printf("NONE\n");
    return 0;
}