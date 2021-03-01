#include <cstdio>
#include <map>
#include <queue>

using namespace std;

const int maxt = 1000 + 10;

int main()
{
    int t, kase = 0;  // t: number of teams; kase: time of scenarios
    while (scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);

        // get team data
        map<int, int> member_to_team;  // member number to team number
        while (t--)
        {
            int n;  // number of a team's members
            scanf("%d", &n);
            while (n--)
            {
                int num;  // indicats a member's id
                scanf("%d", &num);
                member_to_team[num] = t;  // create map: member - team
            }
        }

        // read commands and process
        queue<int> teamq;  // the queue of teams
        queue<int> q[maxt];  // the queue of team[i]'s members
        char command[6];
        while (scanf("%s", command) && command[0] != 'S')
        {
            if (command[0] == 'E')  // ENQUEUE
            {
                int member_number;  // part of enqueue command
                scanf("%d", &member_number);
                int team_number = member_to_team[member_number];
                if (q[team_number].empty()) teamq.push(team_number);
                q[team_number].push(member_number);
            }
            else  // DEQUEUE
            {
                int tmp = teamq.front();
                printf("%d\n", q[tmp].front()); q[tmp].pop();
                if (q[tmp].empty()) teamq.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
