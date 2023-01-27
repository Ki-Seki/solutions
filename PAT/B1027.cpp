#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, level, max, space, ch;
    char c;
    cin >> n >> c;
    level = sqrt((n+1)/2.0);
    max = 2 * level - 1;
    for (int i = level; i >= 1; i--)
    {
        ch = 2 * i - 1;
        space = (max - ch) / 2;
        for (int j = 0 ;j < space; j++) printf(" ");
        for (int j = 0 ;j < ch; j++) printf("%c", c);
        printf("\n");
    }
    for (int i = 2; i <= level; i++)
    {
        ch = 2 * i - 1;
        space = (max - ch) / 2;
        for (int j = 0 ;j < space; j++) printf(" ");
        for (int j = 0 ;j < ch; j++) printf("%c", c);
        printf("\n");
    }
    printf("%d\n", n - (2 * level * level - 1));
    return 0;
}