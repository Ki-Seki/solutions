#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;

int main()
{
    char a[MAX], b[MAX], c[MAX] = {}, mp[] = {'J', 'Q', 'K'};
    scanf("%s %s", a, b);
    int lena = strlen(a) - 1, lenb = strlen(b) - 1, lenc = max(lena, lenb);
    int digit = 1, ta, tb, tmp;
    while (lenc >= 0)
    {
        ta = (lena >= 0 ? a[lena--] - '0' : 0);
        tb = (lenb >= 0 ? b[lenb--] - '0' : 0);

        if (digit % 2)
        {
            tmp = (ta + tb) % 13;
            tmp = tmp >= 10 ? mp[tmp-10] : tmp + '0';
        }
        else
            tmp = (tb + 10 - ta) % 10 + '0';
        
        c[lenc--] = tmp;
        digit++;
    }
    printf("%s", c);
    return 0;
}