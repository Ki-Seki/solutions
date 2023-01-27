#include <iostream>
using namespace std;
int main()
{
    int n, rows;
    char c;
    cin >> n >> c;
    rows = n/2.0+0.5;
    for (int i = 0; i < rows; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < n; j++) printf("%c", c);
            printf("\n");
        }
        else
        {
            printf("%c", c);
            for (int j = 0; j < n - 2; j++) printf(" ");
            printf("%c\n", c);
        }
    }
    return 0;
}