/*
 * hint:
 * 结构体作为 map STL 的键将会报错：no match for 'operator<' (operand types are 'const Node' and 'const Node')
 * 这是因为 map 无法比较两个结构体的大小
 * 解决方法：
 * 1. 不用结构体作为键
 * 2. 自定义比较函数
*/
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int src[] = {0, 0, 1, 1, 2, 2},
          dst[] = {1, 2, 0, 2, 0, 1};

int capacity[3],  // indicate capacity of a, b and c respecitvely
    k;  // the target value
// 既能记录 step，又能当作标识数组 in_queue
map<vector<int>, int> step;  // cups-step map
bool has_output;

void bfs()
{
    vector<int> start(3, 0);
    start[0] = capacity[0];
    queue<vector<int> > q;
    q.push(start);
    step[start] = 0;
    while (!q.empty())
    {
        vector<int> front = q.front();
        q.pop();

        // 终止条件
        if (front[0] == k || front[1] == k || front[2] == k)
        {
            has_output = true;
            printf("yes\n%d\n", step[front]);
            return;
        }

        // 循环分岔口
        for (int i = 0; i < 6; i++)
        {
            // 只要第一个容器不为 0 且 第二个容器不为满
            if (front[src[i]] != 0 && front[dst[i]] != capacity[dst[i]])
            {
                vector<int> tmp = front;
                int move_amount = min(tmp[src[i]], capacity[dst[i]] - tmp[dst[i]]);  // 转移的水量
                tmp[src[i]] -= move_amount;
                tmp[dst[i]] += move_amount;
                if (!step.count(tmp))  // 只要在 step 中未出现，就记录并入栈
                {
                    step[tmp] = step[front] + 1;
                    q.push(tmp);
                }
            }
        }
    }
}

int main()
{
    while (scanf("%d %d %d %d", &capacity[0], &capacity[1], &capacity[2], &k) == 4)
    {
        // initialize
        step.clear();
        has_output = false;
        
        bfs();
        if (!has_output)
            printf("no\n");
    }
    return 0;
}
