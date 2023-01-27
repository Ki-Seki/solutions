#include <bits/stdc++.h>
#define MAX 33
using namespace std;

int n, dst[MAX+2] = {0}, cnt[7+2] = {0}, tmp;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &tmp);
        dst[tmp] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        int matches = 0;
        for (int j = 0; j < 7; j++)
        {
            scanf("%d", &tmp);
            if (dst[tmp]) matches++;
        }
        cnt[matches]++;
    }
    for (int i = 7; i >= 1; i--)
        printf("%d ", cnt[i]);
    return 0;
}