/*
 * hint:
 * strcmp(a, b) 返回 a - b 的值（一种理解记忆返回值的方法）
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100005
using namespace std;

struct Student{
    int id;
    char name[10];
    int grade;
} stu[MAXN];

bool cmp1(Student a, Student b)
{
    return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
    int c = strcmp(a.name, b.name);
    if (c != 0) return c < 0;
    else return a.id < b.id;
}

bool cmp3(Student a, Student b)
{
    if (a.grade != b. grade) return a.grade < b.grade;
    else return a.id < b.id;
}

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
    if (c == 1) sort(stu, stu + n, cmp1);
    else if (c == 2) sort(stu, stu + n, cmp2);
    else sort(stu, stu + n, cmp3);
    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    return 0;
}