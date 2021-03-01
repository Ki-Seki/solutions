#include <iostream>
#include <cstring>
#define MAXN 1005
using namespace std;

struct {
    char name[12], pwd[12];
    bool isOK;
} ans[MAXN];

int main()
{
    int n, m = 0, pos[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", ans[i].name, ans[i].pwd);
        ans[i].isOK = true;
        int len = strlen(ans[i].pwd);
        for (int j = 0; j < len; j++)
        {
            if (ans[i].pwd[j] == '0')
            {
                ans[i].pwd[j] = '%';
                ans[i].isOK = false;
            }
            else if (ans[i].pwd[j] == '1')
            {
                ans[i].pwd[j] = '@';
                ans[i].isOK = false;
            }
            else if (ans[i].pwd[j] == 'l')
            {
                ans[i].pwd[j] = 'L';
                ans[i].isOK = false;
            }
            else if (ans[i].pwd[j] == 'O')
            {
                ans[i].pwd[j] = 'o';
                ans[i].isOK = false;
            }
        }
        if (!ans[i].isOK) pos[m++] = i;
    }

    if (m == 0)
    {
        if (n == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified", n);
    }
    else
    {
        printf("%d\n", m);
        for (int i = 0; i < m; i++)
        {
            printf("%s %s\n", ans[pos[i]].name, ans[pos[i]].pwd);
        }
    }
    
    return 0;
}