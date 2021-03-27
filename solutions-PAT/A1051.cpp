#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int m, n, k;

bool is_possible(queue<int>& seq)
{
    queue<int> ori;
    for (int i = 1; i <= n; i++) ori.push(i);
    stack<int> stk;
    while (true)
    {
        if (ori.empty() && seq.empty() && stk.empty())
            return true;
        else if (!ori.empty() && !seq.empty() && ori.front() == seq.front() && stk.size() < m)
            ori.pop(), seq.pop();  // 实际步骤: stk.push(ori.front()), stk.pop(), ori.pop(), seq.pop();
        else if (!stk.empty() && !seq.empty() && stk.top() == seq.front())
            stk.pop(), seq.pop();
        else if (!ori.empty() && stk.size() < m)
            stk.push(ori.front()), ori.pop();
        else return false;
    }
}

int main()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++)
    {
        queue<int> seq;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            seq.push(tmp);
        }
        printf(is_possible(seq) ? "YES\n" : "NO\n");
    }
    return 0;
}