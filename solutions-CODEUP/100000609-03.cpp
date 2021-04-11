#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    vector<int> mb;  // magic board
    vector<char> step;
} start;
set<vector<int> > in_queue;

void bfs(vector<int> &target)
{
    queue<Node> q;
    q.push(start);
    while (!q.empty())
    {
        Node front = q.front();
        q.pop();

        // 退出条件
        if (front.mb == target)
        {
            printf("%d\n", front.step.size());
            for (int i = 0; i < front.step.size(); i++)
                printf("%c", front.step[i]);
            printf("\n");
            return;
        }

        Node tmp;
        // instruction A
        tmp = front;
        reverse(tmp.mb.begin(), tmp.mb.end());
        if (!in_queue.count(tmp.mb))
        {
            in_queue.insert(tmp.mb);
            tmp.step.push_back('A');
            q.push(tmp);
        }

        // instruction B
        tmp = front;
        tmp.mb.clear();
        tmp.mb.push_back(front.mb[3]);
        for (int i = 0; i < 3; i++)
            tmp.mb.push_back(front.mb[i]);
        for (int i = 5; i < 8; i++)
            tmp.mb.push_back(front.mb[i]);
        tmp.mb.push_back(front.mb[4]);
        if (!in_queue.count(tmp.mb))
        {
            in_queue.insert(tmp.mb);
            tmp.step.push_back('B');
            q.push(tmp);
        }

        // instruction C
        tmp = front;
        tmp.mb[1] = front.mb[6];
        tmp.mb[2] = front.mb[1];
        tmp.mb[5] = front.mb[2];
        tmp.mb[6] = front.mb[5];
        if (!in_queue.count(tmp.mb))
        {
            in_queue.insert(tmp.mb);
            tmp.step.push_back('C');
            q.push(tmp);
        }
    }
}

int main()
{
    // initialize
    for (int i = 0; i < 8; i++)
        start.mb.push_back(i + 1);
    int tmp[8];
    while (scanf("%d%d%d%d%d%d%d%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &tmp[5], &tmp[6], &tmp[7]) == 8)
    {
        // initialize
        vector<int> target;
        for (int i = 0; i < 8; i++)
            target.push_back(tmp[i]);
        in_queue.clear();
        // bfs
        bfs(target);
    }
    return 0;
}
