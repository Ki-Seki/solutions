#include <iostream>
#include <cstring>
#define MAXN 70
using namespace std;

int main()
{
    char s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN], weekday[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    scanf("%s\n%s\n%s\n%s", s1, s2, s3, s4);
    int pos, len = min(strlen(s1), strlen(s2));
    for (pos = 0; pos < len; pos++)
        if (s1[pos] == s2[pos] && 'A' <= s1[pos] && s1[pos] <= 'G')
        {
            printf("%s ", weekday[s1[pos]-'A']);
            break;
        }
    for (pos++; pos < len; pos++)
        if (s1[pos] == s2[pos])
        {
            if ('0' <= s1[pos] && s1[pos] <= '9')
            {
                printf("%02d:", s1[pos] - '0');
                break;
            }
            else if ('A' <= s1[pos] && s1[pos] <= 'N')
            {
                printf("%02d:", s1[pos] - 'A' + 10);
                break;
            }
        }
    len = min(strlen(s3), strlen(s4));
    for (pos = 0; pos < len; pos++)
        if (s3[pos] == s4[pos])
            if (('a' <= s3[pos] && s3[pos] <= 'z') || ('A' <= s3[pos] && s3[pos] <= 'Z'))
            {
                printf("%02d\n", pos);
                break;
            }

    return 0;
}