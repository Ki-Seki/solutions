#include <stdio.h>
#define MAXN 25

// int count = 0;

int dfs(int x, int y, char room[MAXN][MAXN], int h, int w)
{
    int res = 1;
    room[x][y] = '#';
    // printf("%d %d %d\n", ++count, x, y);
    if (x - 1 >= 0 && room[x-1][y] != '#') res += dfs(x-1, y, room, h, w);
    if (x + 1 < h && room[x+1][y] != '#') res += dfs(x+1, y, room, h, w);
    if (y - 1 >= 0 && room[x][y-1] != '#') res += dfs(x, y-1, room, h, w);
    if (y + 1 < w && room[x][y+1] != '#') res += dfs(x, y+1, room, h, w);
    return res;
}

int main()
{
    int w, h;
    while (scanf("%d%d", &w, &h) == 2 && !(w==0 && h==0))
    {
        char room[MAXN][MAXN];
        int x, y, res;
        for (int i = 0; i < h; i++) scanf("%s", room[i]);
        for (int i = 0; i < h; i++) 
            for (int j = 0; j < w; j++) 
                if (room[i][j] == '@')
                    {
                        x = i;
                        y = j;
                    }
        res = dfs(x, y, room, h, w);
        printf("%d\n", res);
    }
    return 0;
}