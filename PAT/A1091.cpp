/*
 * hint:
 * 使用 BFS 解题的典型例题
*/
#include <cstdio>
#include <queue>
#define MAXL 65
#define MAXM 1291
#define MAXN 133

using namespace std;

struct Node
{
    int x, y, z;
};

const int offset_x[] = {1, -1, 0, 0, 0, 0},
          offset_y[] = {0, 0, 1, -1, 0, 0},
          offset_z[] = {0, 0, 0, 0, 1, -1};
int l, m, n, t;
bool cube[MAXL][MAXM][MAXN];

void input()
{
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                scanf("%d", &cube[i][j][k]);
}

// void output_test()
// {
//     printf("\n###\n");
//     for (int i = 0; i < l; i++)
//     {
//         for (int j = 0; j < m; j++)
//             for (int k = 0; k < n; k++)
//                 printf(k == n - 1 ? "%d\n" : "%d ", cube[i][j][k]);
//         printf("\n");
//     }
//     printf("###\n");
// }

bool is_valid_pos(int x, int y, int z)
{
    return (0 <= x && x < l) &&
           (0 <= y && y < m) &&
           (0 <= z && z < n) &&
           cube[x][y][z];
}

int bfs(int x, int y, int z)
{
    int cnt = 0;
    Node start = {x, y, z};
    queue<Node> q;
    q.push(start);
    while (!q.empty())
    {
        Node front = q.front();
        q.pop();
        cnt++;
        cube[front.x][front.y][front.z] = false;
        for (int i = 0; i < 6; i++)
        {
            int new_x = front.x + offset_x[i],
                new_y = front.y + offset_y[i],
                new_z = front.z + offset_z[i];
            if (is_valid_pos(new_x, new_y, new_z))
            {
                Node new_pos = {new_x, new_y, new_z};
                q.push(new_pos);
                cube[new_x][new_y][new_z] = false;
                // output_test();
            }
        }
    }
    // output_test();
    if (cnt >= t) return cnt;
    else return 0;
}

int get_ans()
{
    int ans = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                if (cube[i][j][k] == true)
                    ans += bfs(i, j, k);
    return ans;
}

int main()
{
    input();
    printf("%d", get_ans());
    return 0;
}