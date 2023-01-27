#include <stdio.h>
#include <string.h>

int score(char *s)
{
    int len = strlen(s);
    int o=0, x=0, score=0;
    for (int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case 'O':
            o++;
            score += o;
            break;
        case 'X':
            o = 0;
            break;
        default:
            break;
        }
    }
    return score;
}

int main()
{
    
    char s[90];
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", s);
        printf("%d\n", score(s));
    }
    return 0;
}