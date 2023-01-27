#include <iostream>
#define MAX_TEAM 1005
using namespace std;

int grades[MAX_TEAM] = {};

int main()
{
    int n, team, crew, grade, highest_team = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d-%d %d", &team, &crew, &grade);
        grades[team] += grade;
        if (grades[team] > grades[highest_team])
            highest_team = team;
    }
    printf("%d %d", highest_team, grades[highest_team]);
    return 0;
}