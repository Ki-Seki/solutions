#include <iostream>
#define MAXC 12
using namespace std;

struct {
    char name[MAXC], id[MAXC];
    int grade;
} best={"", "", 0}, worst={"", "", 100}, tmp;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", tmp.name, tmp.id, &tmp.grade);
        if (tmp.grade >= best.grade) best = tmp;
        if (tmp.grade <= worst.grade) worst = tmp;
    }
    printf("%s %s\n%s %s\n", best.name, best.id, worst.name, worst.id);
    return 0;
}