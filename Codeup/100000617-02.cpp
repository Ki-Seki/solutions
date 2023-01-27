#include <cstdio>
#include <queue>
#define MAXN 1005

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        int tmp, ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            q.push(tmp);
        }
        while (q.size() > 1)
        {
            int first = q.top(); q.pop();
            int second = q.top(); q.pop();
            ans += first + second;
            q.push(first + second);
        }
        printf("%d\n", ans);
        while (q.size()) q.pop();
    }
    return 0;
}