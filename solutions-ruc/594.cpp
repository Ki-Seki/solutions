#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int matrix[MAXN][MAXN], n, k;
set<int> all_val;

bool search(int quiz, int now_x, int now_y, int &x, int &y)
{
    if (0 <= now_x && now_x < n && 0 <= now_y && now_y < n)
    {
        if (matrix[now_x][now_y] == quiz)
        {
            x = now_x;
            y = now_y;
            return true;
        }
        if (matrix[now_x][now_y] < quiz)
        {
            return search(quiz, now_x+1, now_y, x, y) || search(quiz, now_x, now_y+1, x, y);
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            all_val.insert(matrix[i][j]);
        }
    scanf("%d", &k);
    while (k--)
    {
        int quiz, x, y;
        scanf("%d", &quiz);
        if (all_val.find(quiz) != all_val.end())
        {
            search(quiz, 0, 0, x, y);
            printf("%d %d\n", x, y);
        }
        else
            printf("-1\n");
    }
    return 0;
}