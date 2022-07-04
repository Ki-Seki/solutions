#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Grade
{
    string name;
    int grade;
} grades[25];

int cmp(Grade& a, Grade& b)
{
    if (a.grade != b.grade) return a.grade > b.grade;
    else return a.name < b.name;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        cin >> grades[i].name >> grades[i].grade;
    sort(grades, grades+n, cmp);
    for (int i = 0; i < n; i++)
        cout << grades[i].name << ' ' << grades[i].grade << endl;
    return 0;
}