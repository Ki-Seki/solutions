/*
* hint:
* 未完全通过
*/
#include <cstdio>
#define MAXK 10005

int k, seq[MAXK], ans[MAXK] = {}, start[MAXK] = {};

int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) scanf("%d", &seq[i]);
    for (int i = 1; i <= k; i++)
        if (ans[i-1] > 0)
        {
            ans[i] = ans[i-1] + seq[i];
            start[i] = start[i-1];
        }
        else
        {
            ans[i] = seq[i];
            start[i] = i;
        }
    int ans_i = 0;
    for (int i = 1; i <= k; i++)
        if (ans[ans_i] < ans[i])
            ans_i = i;
    if (ans[ans_i] <= 0)
        printf("0 %d %d", seq[1], seq[k]);
    else
        printf("%d %d %d", ans[ans_i], seq[start[ans_i]], seq[ans_i]);
    return 0;
}