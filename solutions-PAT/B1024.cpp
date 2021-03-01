#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;

int main()
{
    char num[MAX], sign;
    scanf("%c%s", &sign, num);

    // find 'E'
    int len = strlen(num), pos;
    for (int i = 0; i < len; i++)
        if (num[i] == 'E')
        {
            pos = i;
            break;
        }

    // calculate the absoulte exp, i.e., without sign
    int exp = 0;
    for (int i = pos + 2; i < len; i++)
        exp = exp * 10 + num[i] - '0';

    // output
    if (sign == '-') printf("-");
    if (num[pos+1] == '-')
    {
        // special judge when the exp == 0
        if (exp == 0)  
            for (int i = 1; i < pos; i++)
                printf("%c", num[i]);
        else
        {
            // output zeros with count of exp
            printf("0.");
            for (int i = 0; i < exp - 1; i++) printf("0");
            // output the rest
            printf("%c", num[0]);
            for (int i = 2; i < pos; i++) printf("%c", num[i]);
        }

    }
    else
    {
        if (pos - 2 > exp)  // no need to append zeros
        {
            printf("%c", num[0]);
            for (int i = 2; i < 2 + exp; i++) printf("%c", num[i]);
            printf(".");
            for (int i = 2 + exp; i < pos; i++) printf("%c", num[i]);
        }
        else  // contains that to append no zero
        {
            int zeros = exp - (pos - 2);
            printf("%c", num[0]);
            for (int i = 2; i < pos; i++) printf("%c", num[i]);
            for (int i = 0; i < zeros; i++) printf("0");  // print zeros
        }
    }
    return 0;
}