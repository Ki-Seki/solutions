/*
 * hint:
 * 本题使用了两种方法：
 * 1. 硬核模拟：优先队列 + 快速幂 + 迪杰斯特拉算法。由于每条路径的幂指数都是不同的，所以用一个队列保存路径上所有的指数。
 * 2. 逻辑上的简化：并查集 + 迪杰斯特拉算法。每条路径长度指数式增长，因此先出现的一定是最小的。
*/

// 方法一
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
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
// while implementing fast power algorithm,
// some intermediaries should be long long type
typedef long long LL;

int n, m;

Exps graph[MAXN][MAXN];
bool is_visited[MAXN] = {};

Exps dist[MAXN];

void clear(Exps* start, Exps* end)
{
    while (start < end)
    {
        while (start->size()) start->pop();
        start++;
    }
}

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
    if (m == 0) return 1;
    n %= p;
    if (m & 1)
        return n * fast_power(n, m-1, p) % p;
    else
    {
        LL tmp = fast_power(n, m/2, p) % p;
        return tmp * tmp % p;
    }
}

int cal(Exps &a)
{
    if (a.empty()) return -1;
    LL ans = 0;
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
    while (scanf("%d %d", &n, &m) != EOF)
    {
        // init
        clear(graph[0], graph[0] + MAXN * MAXN);
        memset(is_visited, false, sizeof(is_visited));
        clear(dist, dist + MAXN);
        // input
        for (int i = 0; i < m; i++)
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
    }
    return 0;
}

// // 方法二：
// // 版权声明：本文为CSDN博主「weixin_43886377」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// // 原文链接：https://blog.csdn.net/weixin_43886377/article/details/104361142
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int g[101][101];
// bool visit[101];
// int father[101],d[101];
// int n;
// int INF=0x3fffffff;
// int f(int k)
// {
//     int s=1;
//     for(int i=1; i<=k; i++)
//     {
//         s=(s*2)%100000;
//     }
//     return s;
// }
// void dij(int s)
// {
//     int i,j;
//     fill(visit,visit+101,false);
//     fill(d,d+101,INF);
//     for(i=0; i<n; i++)
//     {
//         d[i]=g[s][i];
//     }
//     d[s]=0;
//     visit[s]=true;
//     for(i=1; i<n; i++)
//     {
//         int Min=INF;
//         int u=-1;
//         for(j=0; j<n; j++)
//         {
//             if(visit[j]==false&&d[j]<Min)
//             {
//                 Min=d[j];
//                 u=j;
//             }
//         }
//         if(u==-1)return;
//         visit[u]=true;
//         for(j=0; j<n; j++)
//         {
//             if(visit[j]==false&&g[u][j]+d[u]<d[j])
//                 d[j]=d[u]+g[u][j];
//         }
//     }
// }
// int findFather(int x)
// {
//     while(x!=father[x])
//         x=father[x];
//     return x;
// }
// int main()
// {
//     int m,i,a,b;
//     while(scanf("%d %d",&n,&m)!=EOF)
//     {
//         for(i=0; i<n; i++)father[i]=i;
//         fill(g[0],g[0]+101*101,INF);
//         for(i=0; i<m; i++)
//         {
//             scanf("%d %d",&a,&b);
//             int fatherA=findFather(a);
//             int fatherB=findFather(b);
//             if(fatherA!=fatherB)
//             {
//                 father[fatherA]=fatherB;
//                 g[a][b]=g[b][a]=f(i);
//             }
//             else continue;
//         }
//         dij(0);
//         for(i=1; i<n; i++)
//         {
//             if(d[i]==INF)printf("-1\n");
//             else printf("%d\n",d[i]%100000);
//         }
//     }
//     return 0;
// }