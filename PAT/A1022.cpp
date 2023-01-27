/*
 * hint:
 * cin 或 scanf 不会消除行末的 '\n'；getline 会消除
 * 因此用 getline 时要防止前面的未消除的换行
 * 
 * 测试点 3，4：考察书编号，是固定 7 位，最后输出时应当用 0 补齐
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map <string, set<int> > title_id, author_id, kw_id, publisher_id, year_id;

void input_kws(string& line, int id)
{
    for (int i = 0; i < line.length(); i++)
    {
        string kw = "";
        while (i < line.length() && line[i] != ' ')
            kw += line[i++];
        kw_id[kw].insert(id);
    }
}

void input()
{
    int n, id;
    string tmp;
    cin >> n;  // n books
    for (int i = 0; i < n; i++)  // for each book
    {
        cin >> id; getchar();
        getline(cin, tmp); title_id[tmp].insert(id);
        getline(cin, tmp); author_id[tmp].insert(id);
        getline(cin, tmp); input_kws(tmp, id);
        getline(cin, tmp); publisher_id[tmp].insert(id);
        cin >> tmp; year_id[tmp].insert(id); getchar();
    }
}

void get_ends(int kase, string& tmp, set<int>::iterator& begin, set<int>::iterator& end)
{
    switch (kase)
    {
    case 1:
        begin = title_id[tmp].begin();
        end = title_id[tmp].end();
        break;
    case 2:
        begin = author_id[tmp].begin();
        end = author_id[tmp].end();
        break;
    case 3:
        begin = kw_id[tmp].begin();
        end = kw_id[tmp].end();
        break;
    case 4:
        begin = publisher_id[tmp].begin();
        end = publisher_id[tmp].end();
        break;
    case 5:
        begin = year_id[tmp].begin();
        end = year_id[tmp].end();
        break;
    }
}

int main()
{
    input();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int kase; scanf("%d: ", &kase);
        string tmp; getline(cin, tmp);
        set<int>::iterator it, end;
        get_ends(kase, tmp, it, end);
        printf("%d: ", kase); cout << tmp << endl;
        if (it == end)
            cout << "Not Found" << endl;
        else
            for (; it != end; it++)
                printf("%07d\n", *it);
    }
    return 0;
}