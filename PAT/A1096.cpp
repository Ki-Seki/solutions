#include <iostream>
#include <cmath>
typedef long long LL;

int main()
{
    LL n, start = 0, len = 0;
    scanf("%lld", &n);
    for (LL i = 2, rt = (LL) sqrt(n); i <= rt; i++)
    {
        if (n % i == 0)
        {
            LL tmp = i, tmp_len = 1, j = i;
            while (n % tmp == 0)
            {
                j++;
                tmp *= j;
                tmp_len++;
            }
            if (tmp_len - 1 > len)
            {
                start = i;
                len = tmp_len - 1;
            }
        }
    }
    if (len)
    {
        printf("%lld\n%lld", len, start);
        for (int i = 1; i < len; i++) printf("*%lld", start + i);
    }
    else printf("1\n%lld", n);
    return 0;
}