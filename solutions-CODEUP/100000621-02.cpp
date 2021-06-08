/*
 * hint:
 * 用硬模拟的方法是愚蠢的，应该要有一定的推理，在本题中，先出现的路径一定比后出现的路径短
 * 重写此题！
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define MAXN 105
#define MOD 100000

struct cmp {
    bool operator ()(int a, int b)
    {
        return a < b;
    }
};

// use queue to store path length
// eg. queue [4, 2, 1] is (2 ^ 4 + 2 ^ 2 + 2 ^ 1) = 22
// esp. [] means INF, [-1] means 0
typedef std::priority_queue<int, std::vector<int>, cmp> Exps;

int n, m;

Exps graph[MAXN][MAXN];
bool is_visited[MAXN] = {};

Exps dist[MAXN];

bool operator < (Exps a, Exps b)
{
    if (!a.empty() && b.empty())
        return true;
    else if (!a.empty() && !b.empty())
    {
        while (a.size() && b.size())
        {
            if (a.top() < b.top())
                return true;
            else if (a.top() > b.top())
                return false;
            a.pop();
            b.pop();
        }
        if (a.size() && a.top())
            return true;
    }
    return false;
}

Exps operator + (Exps &a, Exps &b)
{
    Exps sum = a;
    while (b.size())
    {
        sum.push(b.top());
        b.pop();
    }
    return sum;
}

// start from 0
void dijkstra()
{
    // init
    dist[0].push(-1);
    // n loops
    for (int i = 0; i < n; i++)
    {
        // find unvisited u with min dist between 0 and u
        int u = -1;
        Exps min;
        for (int j = 0; j < n; j++)
            if (dist[j] < min && is_visited[j] == false)
            {
                u = j;
                min = dist[j];
            }
        // end
        if (u == -1) break;
        // mark u as visited
        is_visited[u] = true;
        // update u's neighbors
        for (int j = 0; j < n; j++)
            if (!graph[u][j].empty() && !is_visited[j])
            {
                Exps tmp = dist[u] + graph[u][j];
                if (tmp < dist[j]) dist[j] = tmp;
            }
    }
}

// return n ^ m % p
int fast_power(int n, int m, int p)
{
    n %= p;
    if (m == 0) return 1;
    if (m & 1)
        return n * fast_power(n, m-1, p) % p;
    else
    {
        int tmp = fast_power(n, m/2, p) % p;
        return tmp * tmp % p;
    }
}

int cal(Exps &a)
{
    if (a.empty()) return -1;
    long long ans = 0;
    while (a.size())
    {
        if (a.top() != -1)
            ans = (ans + fast_power(2, a.top(), MOD)) % MOD;
        a.pop();
    }
    return ans;
}

int main()
{
    // input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        // 这里假设不会有重复的路径
    {
        int city1, city2;
        scanf("%d %d", &city1, &city2);
        graph[city1][city2].push(i);
        graph[city2][city1].push(i);
    }
    // dijkstra
    dijkstra();
    // output
    for (int i = 1; i < n; i++)
        printf("%d\n", cal(dist[i]));
    return 0;
}