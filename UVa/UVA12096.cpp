#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>  // contains std::set_union std::set_intersection

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache; // 集合映射为 ID
vector<Set> Setcache; // 根据 ID 取集合

// 查找 ID ，如找不到，则分配新 ID
int ID (Set x)
{
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main()
{
    int kase;
    cin >> kase;
    for (int i = 0; i < kase; i++)
    {
        stack<int> s;
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string op;
            cin >> op;
            if (op[0] == 'P') s.push(ID(Set()));
            else if (op[0] == 'D') s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()]; s.pop();
                Set x2 = Setcache[s.top()]; s.pop();
                Set tmp;
                if (op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(tmp));
                if (op[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(tmp));
                if (op[0] == 'A') { tmp = x2; tmp.insert(ID(x1)); }
                s.push(ID(tmp));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***\n";
    }
}
