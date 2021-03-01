#include <stdio.h>

void count(int n)
{
    int numbers[10] = {0,0,0,0,0,0,0,0,0,0};
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp>0)
        {
            numbers[tmp%10]++;
            tmp /= 10;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("%d", numbers[9]);
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        count(tmp);
        printf("\n");
    }
    return 0;
}