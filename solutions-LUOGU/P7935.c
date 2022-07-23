/*
 * hint:
 * 贪心 + 队列
*/
#include <stdio.h>
#include <stdbool.h>
#define MAXN 100005
int n;
int r1[MAXN], r2[MAXN], r3[MAXN];  // 3 rows
int pos[MAXN];  // pos[i] indicates the position of the i in r1
int cnt_r2[MAXN] = {0}, cnt_r3[MAXN] = {0}; // cnt[i] indicates the number of i in a row

int queue[MAXN], front = 1, tail = 1;  // queue of all missing digits in r2 and r3
bool in_queue[MAXN] = {false};

int main()
{
    // input & init
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&r1[i]);
        pos[r1[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&r2[i]);
        cnt_r2[r2[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&r3[i]);
        cnt_r3[r3[i]]++;
    }

    // find inexistent digits in r2 or r3
    for (int i = 1; i <= n; i++)
        if (cnt_r2[i] == 0 || cnt_r3[i] == 0)
        {
            queue[front++] = i;
            in_queue[i] = true;
        }

    // find answer
    int answer = 0;
    while (front - tail> 0)
    {
        int digit = queue[tail++],
            p = pos[digit];
        cnt_r2[r2[p]]--;
        cnt_r3[r3[p]]--;
        if (cnt_r2[r2[p]] == 0 && in_queue[r2[p]] == false)
        {
            queue[front++] = r2[p];
            in_queue[r2[p]] = true;
        }
        if (cnt_r3[r3[p]] == 0 && in_queue[r3[p]] == false)
        {
            queue[front++] = r3[p];
            in_queue[r3[p]] = true;
        }
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}