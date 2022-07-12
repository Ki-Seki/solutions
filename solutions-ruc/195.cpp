#include <bits/stdc++.h>
using namespace std;

struct Grade {
    int id;
    double avg;
    bool is_valid;
} grades[10005];
int n, valid_records = 0;

bool cmp(const Grade& a, const Grade& b)
{
    if (a.is_valid != b.is_valid) return a.is_valid > b.is_valid;
    else if (a.avg != b.avg) return a.avg > b.avg;
    else return a.id < b.id;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id, cnt, tmp;
        double grade = 0;
        cin >> id >> cnt;
        if (cnt >= 2) valid_records++;
        for (int j = 0; j < cnt; j++)
        {
            cin >> tmp;
            grade += tmp;
        }
        grade = int(grade / cnt * 100) / 100.0;
        grades[i] = {id, grade, cnt>=2};
    }
    sort(grades, grades+n, cmp);
    for (int i = 0; i < valid_records; i++)
        printf("%d %.2f\n", grades[i].id, grades[i].avg);
    if (valid_records == 0) printf("NO\n");
    return 0;
}