#include <iostream>

int main()
{
    int digit[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &digit[i]);
    for (int i = 1; i < 10; i++)
        if (digit[i] != 0)
        {
            printf("%d", i), digit[i]--;
            break;
        }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < digit[i]; j++)
            printf("%d", i);
    return 0;
}