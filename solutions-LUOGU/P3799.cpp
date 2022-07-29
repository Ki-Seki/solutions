// // 方法一：思路简单，但超时，操作次数大概 1e10
// #include <cstdio>
// const int MODSIZE = 1e9+7, MAXN = 1e5, MAXA = 5 * 1e3;
// int n, sticks[MAXN], ans = 0;
// int cnt[MAXA+5] = {0};  // 相同长度单根木棍的数量
// int cntoftwo[MAXA*2+5] = {0};  // 任取两根长度为 a 和 b 的木棍，则 cnt[c]++
// int maxlen = -1;

// int main()
// {
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &sticks[i]);
//         cnt[sticks[i]]++;
//         maxlen = sticks[i] > maxlen ? sticks[i] : maxlen;
//     }
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//             cntoftwo[sticks[i] + sticks[j]]++;
//     for (int len = 1; len <= maxlen; len++)
//         ans = (ans + cnt[len] * (cnt[len] - 1) / 2 * cntoftwo[len]) % MODSIZE;

//     printf("%d\n", ans);
//     return 0;
// }

// 方法二：通过
#include <cstdio>
const int MODSIZE = 1e9+7, MAXN = 1e5, MAXA = 5 * 1e3;
int n, sticks[MAXN], ans = 0;
int cnt[MAXA+5] = {0};  // 相同长度单根木棍的数量
int maxlen = -1;

// 计算 Combination (num, 2)，从 num 个中取 2 个的情况
int cbn2(int num)
{
    return num * (num - 1) / 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sticks[i]);
        cnt[sticks[i]]++;
        maxlen = sticks[i] > maxlen ? sticks[i] : maxlen;
    }
    // 假设四根棍子从短到长为：a, b, c, c
    for (int len = 1; len <= maxlen; len++)  // 遍历每一个长度 c
    {
        if (cnt[len] >= 2)
        {
            for (int a = 1; a <= len / 2; a++)  // 遍历每一个长度 a = c - b
            {
                int b = len - a;
                if (a == b)
                    ans = (ans + cbn2(cnt[len]) * cbn2(cnt[a])) % MODSIZE;
                else
                    ans = (ans + cbn2(cnt[len]) * cnt[a] * cnt[b]) % MODSIZE;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}