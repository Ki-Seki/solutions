#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

char raw[MAXN] = "";
char purged[MAXN] = "";
int dp[MAXN][MAXN];

int main()
{
    while(cin.getline(raw, MAXN))
    {
        // Initialize.
        memset(dp, 0, sizeof(dp));

        // Get purely uppercase string.
        int raw_len = strlen(raw), len = 0;
        for (int i = 0; i < raw_len; i++)
            if (isalpha(raw[i]))
                purged[len++] = 'A' + (islower(raw[i]) ? (raw[i]-'a') : (raw[i]-'A'));
        purged[len] = '\0';

        // Calculate dp[][];
        for (int step = 0; step < len; step++)
            for (int st = 0; st < len - step; st++)
            {
                int ed = st + step;
                if (st == ed) dp[st][ed] = 1;
                else if (st + 1 == ed && purged[st] == purged[ed]) dp[st][ed] = 1;
                else if (purged[st] == purged[ed] && dp[st+1][ed-1]) dp[st][ed] = 1;
                else dp[st][ed] = 0;
            }

        // Find maximum length.
        int max_st = 0, max_len = 0;
        for (int st = 0; st < len; st++)
            for (int ed = len-1; ed >= 0; ed--)
                if (dp[st][ed] && ed-st+1 > max_len)
                {
                    max_st = st;
                    max_len = ed - st + 1;
                }
        
        // Output.
        for (int i = 0, cnt = 0, alpha_i = 0; i < raw_len && cnt < max_len; i++)
        {
            if (isalpha(raw[i]))
                alpha_i++;
            if (max_st < alpha_i && alpha_i <= max_st + max_len)
                printf("%c", raw[i]);
            if (alpha_i == max_st + max_len)
                break;
        }
        printf("\n");
    }
    return 0;
}