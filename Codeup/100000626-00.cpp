#include <bits/stdc++.h>
#define MAXK 10005
using namespace std;

int k, a[MAXK], dp[MAXK];

int main()
{
    while (scanf("%d", &k) == 1 && k != 0)
    {
        bool all_neg = true;
        int max_len = -105, last_st, st, ed;
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > 0) all_neg = false;
            if (i == 1)
                dp[i] = last_st = a[i];
            else
            {
                dp[i] = max(a[i], dp[i-1]+a[i]);
                if (dp[i-1] < 0) last_st = a[i];
            }
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                st = last_st;
                ed = a[i];
            }
        }
        if (all_neg) printf("0 %d %d \n", a[1], a[k]);
        else printf("%d %d %d\n", max_len, st, ed);
    }
    return 0;
}