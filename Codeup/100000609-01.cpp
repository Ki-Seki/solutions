/*
 * hint:
 * 尚未通过，但已通过以下测试样例：
 * 
5
.......A
........
........
........
SSSSSSSS
........
........
U.......

.......A
........
........
........
........
.S......
S.......
US......

....S..A
....S...
....S...
....S...
....S...
....S...
S...S...
US..S...

....S..A
....S...
....SSSS
........
........
.S......
S.......
U.......

....S..A
SS.SS...
....SSSS
SSS.....
...S....
.S.S.S..
S.......
U.......
*/
#include <cstdio>
#define SIZE 8

const int offset_x[] = {-1, 0, -1, 1, -1, 1, 0, 1, 0},
          offset_y[] = {1, 1, 0, 1, -1, 0, -1, -1, 0};
bool matrix[SIZE][SIZE];  // true indicating there is a stone
int clock;

void initialize()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = false;
    clock = 1;
}

void input()
{
    char s[SIZE + 1];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < SIZE; j++)
            if (s[j] == 'S')
                matrix[i][j] = true;
    }
}

bool is_valid_pos(int x, int y)
{
    return (0 <= x && x < SIZE) &&
           (0 <= y && y < SIZE) &&
           !matrix[x - clock][y] &&
           !matrix[x - clock + 1][y];
}

bool dfs(int x, int y)
{
    // 递归边界
    if (clock >= SIZE || (x == 0 && y == 7))  // 在 8 次坠落中，均存活下来了 or 到达终点
        return true;
    
    // 循环分岔口：9 个方向（包含一个停留在原地）
    for (int i = 0; i < 8; i++)  // for each direction
    {
        int new_x = x + offset_x[i],
            new_y = y + offset_y[i];
        if (is_valid_pos(new_x, new_y))
        {
            clock++;
            if (dfs(new_x, new_y))
                return true;
            clock--;
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        initialize();
        input();
        printf(dfs(SIZE - 1, 0) ? "Case #%d: Yes\n" : "Case #%d: No\n", i);
    }
    return 0;
}