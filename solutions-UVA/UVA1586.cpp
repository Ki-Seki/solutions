#include <stdio.h>
#include <string.h>

double weight(char a)
{
    switch (a)
    {
    case 'C': return 12.01;
    case 'H': return 1.008;
    case 'O': return 16.00;
    case 'N': return 14.01;
    default: return 0;
    }
}

double calc(char *s)
{
    int len = strlen(s), num=0;
    double mass = 0;
    char atom = 'X';
    for (int i = 0; i < len; i++)
    {
        if(s[i]=='C' || s[i]=='H' || s[i]=='O' || s[i]=='N')
        {
            if (num==0) num = 1;
            mass += num * weight(atom);
            atom = s[i];
            num = 0;
        }
        else
        {
            num = num * 10 + (s[i]-'0');
        }
    }
    if (num==0) mass += weight(atom);
    else mass = mass + num * weight(atom);
    return mass;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[100];
        scanf("%s", s);
        printf("%.3f\n", calc(s));
    }
    return 0;
}