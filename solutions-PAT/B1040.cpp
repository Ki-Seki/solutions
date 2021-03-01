#include <iostream>
#include <cstring>
#define MAX_LEN 100005
using namespace std;

char str[MAX_LEN];
int acc_p[MAX_LEN] = {}, len;

int main()
{
    // input
    scanf("%s", str);

    // init
    len = strlen(str);
    acc_p[0] = (str[0] == 'P');
    for (int i = 1; i < len; i++)
        acc_p[i] = acc_p[i - 1] + (str[i] == 'P' ? 1 : 0);
    
    // simulate reversely
    int acc_t = 0, ans = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == 'A')
            ans = (ans + acc_p[i - 1] * acc_t) % 1000000007;
        acc_t += (str[i] == 'T');
    }

    // output
    printf("%d", ans);
    return 0;
}