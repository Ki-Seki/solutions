#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

void find_block(int a, int& p, int& h)
{
    for (p = 0; p < n; p++)
        for (h = 0; h < pile[p].size(); h++)
            if (a == pile[p][h]) return;
}

void clear_above(int p, int h)
{
    for (int i = h + 1; i < pile[p].size(); i++)
    {
        int tmp = pile[p][i];
        pile[tmp].push_back(tmp);
    }
    pile[p].resize(h + 1); // 保存前h+1的数据
}

void pile_onto(int p, int h, int p2)
{
    for (int i = h; i < pile[p].size(); i++) 
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h); // 保存前h的数据
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < pile[i].size(); j++) printf(" %d", pile[i][j]);
        printf("\n");
    }
}

int main()
{
    cin >> n;
    string s1, s2;
    int a, b;
    for (int i = 0; i < n; i++) pile[i].push_back(i);
    while ( cin >> s1 >> a >> s2 >> b )
    {
        int pa, pb;
        int ha, hb; // 实际上是下标，而非高度
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb) continue;
        if (s2 == "onto") clear_above(pb, hb);
        if (s1 == "move") clear_above(pa, ha);
        pile_onto(pa, ha, pb);
    }
    print();
    return 0;
}