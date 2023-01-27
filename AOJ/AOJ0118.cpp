#include <stdio.h>
#define MAXN 100

void dfs(char type, int x, int y, int h, int w, char garden[MAXN][MAXN+1])
{
    garden[x][y] = ' ';
    if (x + 1 < h && garden[x+1][y] == type) dfs(type, x+1, y, h, w, garden);
    if (y + 1 < w && garden[x][y+1] == type) dfs(type, x, y+1, h, w, garden);
    if (x - 1 >= 0 && garden[x-1][y] == type) dfs(type, x-1, y, h, w, garden);
    if (y - 1 >= 0 && garden[x][y-1] == type) dfs(type, x, y-1, h, w, garden);
}

int main()
{
    int h, w;
    while (scanf("%d%d", &h, &w) == 2 && !(h==0 && w==0))
    {
        char garden[MAXN][MAXN+1];
        int blocks = 0;
        for (int i = 0; i < h; i++) scanf("%s", garden[i]);
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (garden[i][j] != ' ')
                {
                    dfs(garden[i][j], i, j, h, w, garden);
                    blocks++;
                }
        printf("%d\n", blocks);
    }
    return 0;
}