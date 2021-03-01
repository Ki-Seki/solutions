#include <iostream>
#include <cstring>
#define MAXN 15
using namespace std;

const char ch_num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"},
base[4][5] = {"", "Shi", "Bai", "Qian"};

int main()
{
    bool hasOutput = false, innerNumber = false;
    char tmp[MAXN];
    int num[MAXN] = {};
    cin.getline(tmp, MAXN);
    int len = strlen(tmp), i = 0;

    // special judge
    if (len == 1)
    {
        printf("%s", ch_num[tmp[0]-'0']);
        return 0;
    }
    else if (len == 2 && tmp[0] == '-')
    {
        printf("Fu %s", ch_num[tmp[1]-'0']);
        return 0;
    }

    // get rid of the sign
    if (tmp[0] == '-')
    {
        printf("Fu");
        hasOutput = true;
        i = 1;
    }

    // standardization
    for (; i < len; i++)
        num[len-i] = tmp[i] - '0';

    // output 1 highest digits
    if (num[9] != 0)
    {
        if (hasOutput)
        {
            printf(" %s Yi", ch_num[num[9]]);
            innerNumber = true;
        }
            
        else
        {
            printf("%s Yi", ch_num[num[9]]);
            hasOutput = true;
        }
    }

    // output 4 middle digits
    bool hasZero = false, hasOutputInThisSection = false;
    for (int i = 8; i >= 5; i--)
    {
        if (num[i] != 0)  // non-0 digit
        {
            // handle 0
            if (hasZero)
            {
                printf(" ling");
                hasZero = false;
            }

            // handle number
            if (hasOutput) printf(" ");
            printf("%s", ch_num[num[i]]);

            // handle base
            if ((i-1) % 4 != 0) printf(" %s", base[(i-1)%4]);

            // handle status
            hasOutput = true;
            hasOutputInThisSection = true;
            innerNumber = true;
        }
        else  // 0 digit
        {
            if (innerNumber) hasZero = true;
        }
    }
    if (hasOutputInThisSection) printf(" Wan");
    if (hasOutput && !hasOutputInThisSection) printf(" ling");

    // output 4 low digits
    hasZero = false;
    for (int i = 4; i >= 1; i--)
    {
        if (num[i] != 0)  // non-0 digit
        {
            // handle 0
            if (hasZero)
            {
                printf(" ling");
                hasZero = false;
            }

            // handle number
            if (hasOutput) printf(" ");
            printf("%s", ch_num[num[i]]);

            // handle base
            if ((i-1) % 4 != 0) printf(" %s", base[(i-1)%4]);

            // handle status
            hasOutput = true;
        }
        else  // 0 digit
        {
            if (innerNumber) hasZero = true;
        }
    }
    return 0;
}