#include <stdio.h>
#include <string.h>


bool input(char puzzle[5][6])
{
    for (int i = 0; i < 5; i++)
    {
        char tmp[6];
        gets(tmp);
        if (strcmp(tmp, "Z") != 0) // that is if tmp != "Z"
        {
            memcpy(puzzle[i], tmp, sizeof(tmp));
            puzzle[i][5] = '\0';
        }
        else
            return false;
    }
    return true;
}

// bool input(char puzzle[5][6]) // read the puzzle grid
// {
//     int i;
//     for (i = 0; i < 5; i++)
//     {
//         char tmp[6];
//         gets(tmp);
//         // printf("###### The i is equal to %d\n", i);
//         // while (strlen(tmp) == 0) gets(tmp);
//         if (strcmp(tmp, "Z") != 0) // that is if tmp != "Z"
//         {
//             memcpy(puzzle[i], tmp, sizeof(tmp));
//             if (puzzle[i][4] == '\0') // in case the rightmost is an empty pos.
//             {
//                 puzzle[i][4] = ' ';
//                 puzzle[i][5] = '\0';
//             }
//         }
//         else
//             return false;
//     }
//     return true;
// }

bool puzzle_solve(char puzzle[5][6]) // solve the puzzle while read the moves seq
{
    int blankX = 0, blankY = 0;

    for (int i = 0; i < 5; i++) // find the blank sp
    {
        for (int j = 0; j < 5; j++)
        {
            if (puzzle[i][j] == ' ')
            {
                blankX = i;
                blankY = j;
            }
        }
    }

    do // moves
    {
        char tmp = getchar();

        switch (tmp)
        {
        case 'A':
            if (blankX - 1 >= 0)
            {
                puzzle[blankX][blankY] = puzzle[blankX-1][blankY];
                blankX--;
            }
            else
            {
                char cache[80];
                gets(cache);
                return false;
            }
            break;
        case 'B':
            if (blankX + 1 <= 4)
            {
                puzzle[blankX][blankY] = puzzle[blankX+1][blankY];
                blankX++;
            }
            else
            {
                char cache[80];
                gets(cache);
                return false;
            }
            break;
        case 'L':
            if (blankY - 1 >= 0)
            {
                puzzle[blankX][blankY] = puzzle[blankX][blankY-1];
                blankY--;
            }
            else
            {
                char cache[80];
                gets(cache);
                return false;
            }
            break;
        case 'R':
            if (blankY + 1 <= 4)
            {
                puzzle[blankX][blankY] = puzzle[blankX][blankY+1];
                blankY++;
            }
            else
            {
                char cache[80];
                gets(cache);
                return false;
            }
            break;
        }
        if (tmp == '0') break;
        
    } while (true);
    
    puzzle[blankX][blankY] = ' ';
    return true;
}

void output(char puzzle[5][6])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", puzzle[i][j]);
            if (j < 4) printf(" ");
        }
        if (i < 4) printf("\n");
    }
}

int main()
{
    char puzzle[5][6], moves[90];
    int i = 1;
    bool notFirst = false;
    while (input(puzzle))
    {
        printf("\n######## test ##########\n");
        output(puzzle);
        printf("\n######## test ##########\n");

        if (notFirst) printf("\n");
        notFirst = true;
        if (puzzle_solve(puzzle))
        {
            printf("Puzzle #%d:\n", i);
            output(puzzle);
            printf("\n");
        }
        else
        {
            printf("Puzzle #%d:\n", i);
            printf("This puzzle has no final configuration.\n");
        }
        i++;
    }
    return 0;
}