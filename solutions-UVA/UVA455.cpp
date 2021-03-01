#include <stdio.h>
#include <string.h>

void solve()
{
    char str[85];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 1; i <= len; i++)
    {
        if (len%i == 0)
        {
            bool flag = true;
            for (int j = i; j < len; j++)
            {
                if (str[j] != str[j%i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        solve();
        if (i < n - 1)
        {
            printf("\n");
        }
        
    }
    return 0;
}