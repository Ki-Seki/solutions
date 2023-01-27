#include <iostream>

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; n / i > 0; i *= 10)
    {
        int left = n / (i * 10),
            mid = n / i % 10,
            right = n % i;
        ans += left * i
            + (mid == 1 ? right + 1 : 0)
            + (mid > 1 ? i : 0);
    }
    printf("%d", ans);
    return 0;
}