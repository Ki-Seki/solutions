#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#define MAXN 10005

int n;

int set[MAXN];  // union-find set

std::vector<int> edge[MAXN];  // adjacency list
bool is_visited[MAXN] = {};

void init()
{
    for (int i = 0; i < MAXN; i++)
        set[i] = i;
}

int find(int x)
{
    if (set[x] == x)
        return x;
    else
        return set[x] = find(set[x]);
}

void union_sets(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a != root_b)
        set[root_a] = root_b;
}

int calculate_components(int begin, int end)
{
    std::set<int> components;
    for (; begin <= end; begin++)
        components.insert(find(begin));
    return components.size();
}

void dfs(int n, int now_depth, int depth[], int &max_depth)
{
    is_visited[n] = true;
    depth[n] = now_depth;
    if (now_depth > max_depth)
        max_depth = now_depth;

    for (int i = 0; i < edge[n].size(); i++)
    {
        int node = edge[n][i];
        if (is_visited[node] == false)
            dfs(node, now_depth + 1, depth, max_depth);
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        union_sets(a, b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int components = calculate_components(1, n);
    if (components != 1)
        printf("Error: %d components", components);
    else
    {
        std::set<int> ans;  // store answers of nodes
        int depth[MAXN];  // depth[i] stores the depth from a particular node to node i
        int max_depth;

        memset(is_visited, 0, sizeof(is_visited));
        memset(depth, 0, sizeof(depth));
        max_depth = -1;
        dfs(1, 1, depth, max_depth);
        for (int i = 1; i <= n; i++)
            if (depth[i] == max_depth)
                ans.insert(i);
        
        memset(is_visited, 0, sizeof(is_visited));
        memset(depth, 0, sizeof(depth));
        max_depth = -1;
        dfs(*ans.begin(), 1, depth, max_depth);
        for (int i = 1; i <= n; i++)
            if (depth[i] == max_depth)
                ans.insert(i);
        
        for (std::set<int>::iterator it = ans.begin(); it != ans.end(); it++)
            printf("%d\n", *it);
    }
    return 0;
}