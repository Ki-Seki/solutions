#include <iostream>

using namespace std;

int main()
{
    int n, tmp, cnt[5] = {0}, ans[5] = {0}, a2_sign = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        switch (tmp % 5)
        {
        case 0:
            if (tmp % 2 == 0) ans[0] += tmp;
            cnt[0]++;
            break;
        case 1:
            ans[1] += a2_sign * tmp;
            a2_sign *= -1;
            cnt[1]++;
            break;
        case 2:
            cnt[2]++;
            break;
        case 3:
            ans[3] += tmp;
            cnt[3]++;
            break;
        case 4:
            if (tmp > ans[4]) ans[4] = tmp;
            cnt[4]++;
            break;
        }
    }
    ans[2] = cnt[2];
    if (cnt[0] && ans[0]) printf("%d ", ans[0]); else printf("N ");
    if (cnt[1]) printf("%d ", ans[1]); else printf("N ");
    if (cnt[2]) printf("%d ", cnt[2]); else printf("N ");
    if (cnt[3]) printf("%.1f ", 1.0 * ans[3] / cnt[3]); else printf("N ");
    if (cnt[4]) printf("%d", ans[4]); else printf("N");
    return 0;
}