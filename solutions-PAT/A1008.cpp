#include <iostream>

int main()
{
    int n, last = 0, tmp, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        ans += (tmp > last) ? (tmp - last) * 6 : (last - tmp) *4;
        last = tmp;
    }
    printf("%d", ans + n * 5);
    return 0;
}