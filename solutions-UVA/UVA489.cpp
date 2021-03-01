#include <stdio.h>
#include <string.h>
#define MAXN 100
#define CHANCE 7

int solve(char puzzle[], char guess[])
{
    int res = 3, lenP = strlen(puzzle), lenG = strlen(guess), left = strlen(puzzle), chance = CHANCE;
    for (int i = 0; i < lenG; i++)
    {
        bool isCorrect = false;
        for (int j = 0; j < lenP; j++)
        {
            if (guess[i] == puzzle[j])
            {
                left--;
                puzzle[j] = '\0';
                isCorrect = true;
            }
        }
        if (!isCorrect) chance--;
        if (chance > 0)
        {
            if (left <= 0)
            {
                return 1;
            }
        }
        else
        {
            return 2;
        }
    }
    if (chance > 0)
    {
        if (left <= 0)
        {
            return 1;
        }
        else
        {
            return 3;
        }
        
    }
    else
    {
        return 2;
    }
}

int main()
{
    char puzzle[MAXN], guess[MAXN];
    int rnd;
    while (scanf("%d%s%s", &rnd, puzzle, guess) == 3 && rnd != -1)
    {
        printf("Round %d\n", rnd);
        switch (solve(puzzle, guess))
        {
        case 1:
            printf("You win.\n");
            break;
        case 2:
            printf("You lose.\n");
            break;
        case 3:
            printf("You chickened out.\n");
        }
    }
    return 0;
}