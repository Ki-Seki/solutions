// 方法一：使用图的深度优先搜索算法
/*
#include <iostream>
#include <string>
#include <map>
#include <set>
#define MAXN 2002

using namespace std;

typedef pair<string, int> gang;  // 存储团伙的头目和成员数

int n, k;

map<string, int> name2id;
map<int, string> id2name;
int person_cnt = 0;  // 总人数

bool is_visited[MAXN] = {};
int edge[MAXN][MAXN] = {};  // 边权
int vertex[MAXN] = {};  // 点权

set<gang> gangs;  // 团伙的集合

// 给 name 分配 id，填充 name2id 和 id2name；
// 若已经分配过，就直接返回 id
int get_id(string name)
{
    if (name2id.find(name) != name2id.end())
        return name2id[name];
    name2id[name] = person_cnt;
    id2name[person_cnt] = name;
    return person_cnt++;
}

// 遍历与 n 相连的连通块，并得到以下值：
// gang_id：团伙头目的 id；
// member_cnt：团伙成员数；
// twe：total weight of edgs，总边权
void dfs(int n, int &gang_id, int &member_cnt, int &twe)
{
    is_visited[n] = true;

    if (vertex[n] > vertex[gang_id])
        gang_id = n;
    member_cnt++;

    for (int i = 0; i < person_cnt; i++)
        if (edge[n][i])  // 判断并访问边
        {
            twe += edge[n][i];
            edge[n][i] = edge[i][n] = 0;  // 删除边要双向删除
            if (!is_visited[i])  // 判断并访问点
                dfs(i, gang_id, member_cnt, twe);
        }
}

void graph_traversal()
{
    for (int i = 0; i < person_cnt; i++)
        if (!is_visited[i])
        {
            int gang_id = i, member_cnt = 0, twe = 0;
            dfs(i, gang_id, member_cnt, twe);
            if (member_cnt > 2 && twe > k)
                gangs.insert(make_pair(id2name[gang_id], member_cnt));
        }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int w;
        cin >> a >> b >> w;
        int ida = get_id(a), idb = get_id(b);
        vertex[ida] += w;
        vertex[idb] += w;
        edge[ida][idb] += w;
        edge[idb][ida] += w;
    }
    graph_traversal();
    cout << gangs.size() << endl;
    for (set<gang>::iterator it = gangs.begin(); it != gangs.end(); it++)
        cout << it->first << ' ' << it->second << endl;
    return 0;
}
*/

// 方法二：使用并查集，有更多的地方存在优化的可能

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define MAXN 20000

struct Node
{
    int father;
    int weight;
    int count;  // count of members
};

int n, k;

Node set[MAXN];  // union-find set

std::set<int> all_occured_id;
std::set<int> ans_id;

void init()
{
    for (int i = 0; i < MAXN; i++)
        set[i] = {i, 0, 1};
}

int find(int x)
{
    int root = x;
    while (set[root].father != root)
        root = set[root].father;
    return root;
}

void union_sets(int a, int b)
{
    int root_a = find(a), root_b = find(b);
    if (root_a == root_b) return;
    if (set[root_a].weight < set[root_b].weight)
        std::swap(root_a, root_b);
    set[root_b].father = root_a;
    set[root_a].count += set[root_b].count;
}

char* int2cstr(int id)
{
    char* name = new char[4];
    name[0] = id / 676 + 'A';
    name[1] = id % 676 / 26 + 'A';
    name[2] = id % 26 + 'A';
    name[4] = '\0';
    return name;
}

int cstr2int(char* name)
{
    return (name[0] - 'A') * 676 + (name[1] - 'A') * 26 + (name[2] - 'A');
}

int refind(int x)
{
    // find node, max, whose weight is max
    int max = x,
        root = x;
    while (set[root].father != root)
    {
        if (set[root].weight >= set[max].weight)
            max = root;
        root = set[root].father;
    }

    // if max is not root, then make it root
    if (max != root  && set[max].weight > set[root].weight)
    {
        int another = set[max].father;
        set[max].father = max;  // max is a new root
        set[max].count = set[root].count;  // copy the count of root
        set[root].father = max;  // union two sets
    }
    return max;
}

int main()
{
    init();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        char name1[4], name2[4];
        int id1, id2, weight;
        scanf("%s %s %d", name1, name2, &weight);
        id1 = cstr2int(name1);
        id2 = cstr2int(name2);
        set[id1].weight += weight;
        set[id2].weight += weight;
        union_sets(id1, id2);
        all_occured_id.insert(id1);
        all_occured_id.insert(id2);
    }

    // re-organize the root
    for (std::set<int>::iterator it = all_occured_id.begin();
         it != all_occured_id.end(); it++)
        refind(*it);  // make the max node become the root

    // calculate the total weight
    // by this mean, total weight is twice bigger than genuine total weight
    for (std::set<int>::iterator it = all_occured_id.begin();
         it != all_occured_id.end(); it++)
    {
        int root = find(*it);
        if (root != *it)
            set[root].weight += set[*it].weight;
    }

    // filter into answers
    for (std::set<int>::iterator it = all_occured_id.begin();
         it != all_occured_id.end(); it++)
    {
        int root = find(*it);
        if (set[root].count > 2 && set[root].weight / 2 > k)  // eliminate the two-fold issue caused by above
            ans_id.insert(root);
    }

    // output
    printf("%d\n", ans_id.size());
    for (std::set<int>::iterator it = ans_id.begin();
         it != ans_id.end(); it++)
        printf("%s %d\n", int2cstr(*it), set[*it].count);
    return 0;
}