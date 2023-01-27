#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int offset[] = {-3, +3, -1, +1};

struct Node {
    vector<int> matrix;
    int step;
} start;
vector<int> target;
set<vector<int> > inq;

bool is_achieved(vector<int> &v)
{
    for (int i = 0; i < 9; i++)
        if (v[i] != target[i])
            return false;
    return true;
}

bool is_valid_offset(int pos, int offset)
{
    int x = pos / 3, y = pos % 3,
        offset_x = offset / 3, offset_y = offset % 3,
        new_x = x + offset_x, new_y = y + offset_y;
    return (0 <= new_x && new_x < 3) &&
           (0 <= new_y && new_y < 3);
}

int bfs()
{
    queue<Node> q;
    q.push(start);
    inq.insert(start.matrix);
    while (!q.empty())
    {
        Node front = q.front();
        q.pop();

        if (is_achieved(front.matrix)) return front.step;

        // find the blank space
        int blank;
        for (int i = 0; i < 9; i++)
            if(front.matrix[i] == 0)
            {
                blank = i;
                break;
            }
        
        // 岔路口
        for (int i = 0; i < 4; i++)
            if (is_valid_offset(blank, offset[i]))
            {
                swap(front.matrix[blank], front.matrix[blank + offset[i]]);
                if (!inq.count(front.matrix))
                {
                    inq.insert(front.matrix);  // mark as in-queued
                    front.step++;
                    q.push(front);
                    front.step--;  // recver;
                }
                swap(front.matrix[blank], front.matrix[blank + offset[i]]);  // revcover
            }
    }
    return 0;
}

int main()
{
    int tmp;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &tmp);
        start.matrix.push_back(tmp);
    }
    start.step = 1;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &tmp);
        target.push_back(tmp);
    }
    printf("%d", bfs());
    return 0;
}
