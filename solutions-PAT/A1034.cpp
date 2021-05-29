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