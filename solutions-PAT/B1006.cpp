#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[4];
    scanf("%s", str);
    int len = strlen(str), cnt;
    if (len == 3)
    {
        cnt = str[0] - '0';
        for (int i = 0; i < cnt; i++) printf("B");
        cnt = str[1] - '0';
        for (int i = 0; i < cnt; i++) printf("S");
        cnt = str[2] - '0';
        for (int i = 1; i <= cnt; i++) printf("%d", i);
    }
    else if (len == 2)
    {
        cnt = str[0] - '0';
        for (int i = 0; i < cnt; i++) printf("S");
        cnt = str[1] - '0';
        for (int i = 1; i <= cnt; i++) printf("%d", i);
    }
    else
    {
        cnt = str[0] - '0';
        for (int i = 1; i <= cnt; i++) printf("%d", i);
    }
    cout << endl;
    return 0;
}