#include <iostream>
using namespace std;

int main()
{
    double info[3][3];
    int sel[3];
    char map[3] = {'W', 'T', 'L'};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> info[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int max = 0;
        for (int j = 0; j < 3; j++)
        {
            if (info[i][j] >= info[i][max]) max = j;
        }
        sel[i] = max;
    }
    double profit = (info[0][sel[0]] * info[1][sel[1]] * info[2][sel[2]] * 0.65 - 1) * 2.0;
    printf("%c %c %c %.2f\n", map[sel[0]], map[sel[1]], map[sel[2]], profit);
    return 0;
}