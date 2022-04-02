/*
 * hint:
 * 该题未解决，原因在于人为增加约束，认为时间有最大值，但实际上并没有，这同时导致了我的算法空间复杂度极高
 * 该题从 1 开始计数
*/
#include <bits/stdc++.h>
#define MAXM 21
#define MAXN 21
#define MAXTIME 999999999
using namespace std;

int n, m;
int arrangement[MAXM * MAXN][2] = {0};  // 工件号-工序号
int process_table[MAXN][MAXM][2] = {0};  // 机器号-加工时间
int machine_usage[MAXM][MAXTIME] = {0};  // 第 i 个机器 [j, j+1] 时段被 machine_usage[i][j] 号工件占用（为 0 则不被任何工件占用）
int machine_head[MAXM] = {0};  // 第 i 个机器最晚的工作结束时间是 machine_head[i] 时刻
int machine_idle[MAXM][MAXTIME]; // 第 i 个机器从 j 时起，有 machine_idle[i][j] 的空闲时间

void input()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &arrangement[i][0]);
    
    // 计算工序号
    for (int i = 1; i <= n * m; i++)
    {
        int last = 0;  // 上一个 arrangement[i][0] 号工件的工序数
        for (int j = i - 1; j > 0; j--)
            if (arrangement[j][0] == arrangement[i][0])
            {
                last = arrangement[j][1];
                break;
            }
        arrangement[i][1] = last + 1;
    }

    // 读入各工件-工序对应的机器-时长
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &process_table[i][j][0]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &process_table[i][j][1]);

}

int find_latest_finised(int part)
{
    int latest = 0;
    for (int i = 1; i <= m; i++)
        for (int j = machine_head[i]; j > 0; j--)
            if (machine_usage[i][j] == part && j > latest)
                latest = j + 1;
    return latest;
}

int find_earliest_beginning(int latest, int machine, int length)
{
    for (int i = latest; i < MAXTIME; i++)
        if (machine_idle[machine][i] > length)
            return i;
}

int main()
{
    fill(machine_idle[0], machine_idle[0] + MAXM * MAXTIME, MAXTIME);
    input();

    // 按照安排顺序，依次处理
    for (int i = 1; i <= n * m; i++)
    {
        int part = arrangement[i][0], 
            order = arrangement[i][1], 
            machine = process_table[part][order][0],
            length = process_table[part][order][1];

        // 找到 part 工件在其他机器上的最晚结束时间
        int latest = find_latest_finised(part);

        // 找到最早 machine 机器可以插入 length 的位置
        int earlist = find_earliest_beginning(latest, machine, length);

        // 更新 machine_usage
        fill(machine_usage[machine] + earlist, machine_usage[machine] + earlist + length, part);

        // 更新 machine_head
        if (earlist + length > machine_head[machine])
            machine_head[machine] = earlist + length;

        // 更新 machine_idle
        for (int i = earlist; i < earlist + length; i++)
            machine_idle[machine][i] = 0;
        int acc_idle = 1;
        for (int i = earlist - 1; i >= 0; i--)
            if (machine_idle[machine][i] != 0)
                machine_idle[machine][i] = acc_idle++;
            else
                break;
    }

    // 找到最晚结束运行的机器的时间
    int max_time = 0;
    for (int i = 1; i <= m; i++)
        if (machine_head[i] > max_time)
            max_time = machine_head[i];
    printf("%d", max_time);
    return 0;
}