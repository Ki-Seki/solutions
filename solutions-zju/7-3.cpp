#include <cstdio>
#include <cstring>
#define MAX 10

struct Time {
    int h, m;
};

Time table[MAX + 1][MAX + 1];

int n, m;
char str_time[10];
int tmp1, tmp2;
int path[MAX + 1];  // 暂存每个城市选择的线路

Time st = {0, 0}, ed = {23, 59};  // best starting and ending time

bool operator <= (Time a, Time b)
{
    if (a.h <= b.h) return true;
    else if (a.h == b.h && a.m <= b.m) return true;
}

Time operator + (Time a, int b)
{
    Time ans = {a.h, a.m + b};
    return ans;
}

void dfs(int city)  // 当前到达的城市
{
    if (city == n)
    {
        if (table[path[n]][n] <= ed) 
        {
            ed = table[path[n]][n];
            if (st <= table[path[1]][1])
                st = table[path[1]][1];
        }
        return;
    }
    for (int line = 1; line <= m; line++)
    {
        if (table[line][city].h != -1)
        {
            path[city] = path[city-1];
            dfs(city + 1);
        }
        if (table[line][city].h != -1 && table[path[city-1]][city-1] + 5 <= table[line][city])
        {
            path[city] = line;
            dfs(city + 1);
        }
    }
}

int main()
{
    // input
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%s", str_time);
            if (str_time[0] == '-')
                table[i][j] = {-1, -1};
            else
            {
                sscanf(str_time, "%d:%d", &tmp1, &tmp2);
                table[i][j] = {tmp1, tmp2};
            }
        }
    
    // init border
    for (int i = 0; i <= m; i++) table[i][0] = {0, 0};
    for (int i = 0; i <= n; i++) table[0][i] = {0, 0};
    
    // // traverse all possible paths
    // Time now = {0, 0};
    
    // for (int city = 1; city <= n; city++)
    // {
    //     for (int line = 1; line <= m; line++)
    //     {
    //         if (table[line][city].h != -1 && table[path[city-1]][city-1] + 5 <= table[line][city])
    //         {
    //             path[city] = line;
    //             if (city == n)
    //             {
    //                 // 这里涉及多目标问题，先保留
    //                 if (st <= table[path[1]][1]) st = table[path[1]][1];
    //                 if (table[path[n]][n] <= ed) ed = table[path[n]][n];
    //             }
    //             // else
    //             //     now = table[line][city+1] + 5;
    //         }
    //         else
    //             continue;
    //     }
    // }
    for (int line = 1; line <= m; line++)  // 开始时用哪条 line
    {
        if (table[line][1].h != -1)
        {
            path[0] = line;
            dfs(1);
        }
    }

    // output answer
    printf("%02d:%02d %02d:%02d", ed.h, ed.m, st.h, st.m);
    return 0;
}