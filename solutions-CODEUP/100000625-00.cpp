#include <iostream>
#include <cstring>
#define MAXN 40
using namespace std;
typedef long long LL;

int n;
LL f[MAXN] = {0, 1};

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 2; i <= n; i++)
            f[i] = f[i-1] + f[i-2];
        printf("%d\n", f[n]);
    }
    return 0;
}