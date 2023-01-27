/*
 * hint:
 * 测试点3：含有年龄为 200 的数据，注意定义数组的边界大小
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100005
#define MAXAGE 205
using namespace std;

struct Person{
    char name[10];
    int age, worth;
} rcd[MAXN], new_rcd[MAXN];

int age[MAXAGE] = {};  // denote the count of people with age of index

bool cmp(Person a, Person b)
{
    if (a.worth != b.worth) return a.worth > b. worth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%s %d %d", rcd[i].name, &rcd[i].age, &rcd[i].worth);
    
    // sort
    sort(rcd, rcd + n, cmp);

    // preprocess: delete redundant data
    int new_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (age[rcd[i].age] <= 100)
        {
            age[rcd[i].age]++;
            new_rcd[new_n++] = rcd[i];
        }
    }

    // output
    for (int kase = 1; kase <= k; kase++)
    {
        printf("Case #%d:\n", kase);
        bool hasOutput = false;
        int m, l, r;
        scanf("%d %d %d", &m, &l, &r);
        for (int i = 0; i < new_n && m > 0; i++)
        {
            if (l <= new_rcd[i].age && new_rcd[i].age <= r)
            {
                hasOutput = true;
                m--;
                printf("%s %d %d\n", new_rcd[i].name, new_rcd[i].age, new_rcd[i].worth);
            }
        }
        if (!hasOutput) printf("None\n");
    }
    return 0;
}