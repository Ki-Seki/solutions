#include <bits/stdc++.h>
int n, left, right;
char s[26];
int cnt[12 + 1] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012};  // 打表求出

void dfs(int i)
{
    if (i > n*2)
    {
        printf("%s\n", s+1);
        return;
    }
    // 选左
    if (left < n)
    {
        s[i] = '(';
        left++;
        dfs(i+1);
        left--;
    }
    // 选右
    if (left - right > 0)
    {
        s[i] = ')';
        right++;
        dfs(i+1);
        right--;
    }
}

int main()
{

    scanf("%d", &n);
    printf("%d\n", cnt[n]);
    dfs(1);
    return 0;
}