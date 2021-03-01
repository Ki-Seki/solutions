#include <iostream>
using namespace std;

struct {
    char name[15], id[15];
    int grade;
} f={"", "", -1}, m={"", "", 101}, tmp;

int main()
{
    int n, diff;
    char sex;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %c %s %d", tmp.name, &sex, tmp.id, &tmp.grade);
        if (sex == 'M' && tmp.grade <= m.grade) m = tmp;
        if (sex == 'F' && tmp.grade >= f.grade) f = tmp;
    }
    if (f.grade != -1) printf("%s %s\n", f.name, f.id); else printf("Absent\n");
    if (m.grade != 101) printf("%s %s\n", m.name, m.id); else printf("Absent\n");
    if(f.grade != -1 && m.grade != 101) printf("%d\n", f.grade-m.grade); else printf("NA\n");
    return 0;
}