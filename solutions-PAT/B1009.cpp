#include <iostream>
#define MAXN 85
using namespace std;

int main()
{
    char words[MAXN][MAXN];
    int cnt = 0;
    while (scanf("%s", words[cnt]) != EOF)
        cnt++;
    while (cnt)
        printf(cnt-1 ? "%s " : "%s\n", words[cnt-1]), cnt--;
    return 0;
}