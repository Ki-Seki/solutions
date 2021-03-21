/*
 * hint:
 * getline 
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

map <string, set<int> > title_id, author_id, kw_id, publisher_id, year_id;

void input()
{
    int n, id;
    string tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id; getchar();
        getline(cin, tmp);
        title_id[tmp].insert(id);
        // char c = getchar();
        getline(cin, tmp);
        author_id[tmp].insert(id);
    }
}

int main()
{
    input();
    return 0;
}