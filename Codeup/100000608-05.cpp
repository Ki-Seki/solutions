/*
 * hint:
 * 重要陷阱：不要忘记初始化状态，也即起点
 * 启示：应该学会找到临界值，特殊值去测试！
*/
#include <cstdio>
#include <iostream>
#include <vector>
#define MAX_SIZE 16

using std::pair;
using std::vector;
using std::make_pair;

typedef pair<int, int> Coord;

const int x[4] = {0, -1, 0, 1}, y[4] = {-1, 0, 1, 0};  // offset

int n, m;
bool maze[MAX_SIZE][MAX_SIZE] = {};
Coord start, end;
vector<Coord> path;
bool has_output = false;

void input()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &maze[i][j]);
    scanf("%d %d %d %d", &start.first, &start.second, &end.first, &end.second);
}

void output()
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        printf(i == size - 1 ? "(%d,%d)\n" : "(%d,%d)->", path[i].first, path[i].second);
}

bool is_valid_pos(int x, int y)
{
    return (1 <= x && x <= n) &&
           (1 <= y && y <= m) &&
           maze[x][y];
}

// 已走到 pos，在 pos 处进行考察
void dfs(Coord pos)
{
    // 递归边界
    if (pos == end)
    {
        output();
        has_output = true;
        return;
    }

    // 循环分岔口
    for (int i = 0; i < 4; i++)
    {
        int next_x = pos.first + x[i],
            next_y = pos.second + y[i];
        if (is_valid_pos(next_x, next_y))
        {
            maze[next_x][next_y] = false;
            path.push_back(make_pair(next_x, next_y));
            dfs(make_pair(next_x, next_y));
            maze[next_x][next_y] = true;
            path.pop_back();
        }
    }
}

int main()
{
    input();

    // initialize
    maze[start.first][start.second] = false;
    path.push_back(start);

    dfs(start);
    if(!has_output) printf("-1");
    return 0;
}