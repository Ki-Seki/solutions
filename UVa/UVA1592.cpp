#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int n, m;  // n rows and m columns
string s, s_tmp;
map<string, int> idmp;  // id of string

// get id of string - s, if exists, or allocate an id
int getId(string s)
{
    if (idmp.find(s) == idmp.end())
    {
        idmp.insert({s, idmp.size()});
    }
    return idmp[s];
}

int main()
{
    while (cin >> n >> m)
    {
        // initialize
        getchar();
        vector<int> table[n+1];
        idmp.clear();

        // input
        for (int i = 0; i < n; i++)
        {
            getline(cin, s);  // cin -> s
            stringstream input(s);  // initialize input with s
            while (getline(input, s_tmp, ','))  // use ',' as delimiter
                table[i].push_back(getId(s_tmp));
        }
        
        bool isPNF = true;
        
        // traversal for any two columns
        for (int i = 0; i < m-1 && isPNF; i++)
        {
            for (int j = i+1; j < m && isPNF; j++)
            {
                map<pair<int, int>, int> pos;  // 两列对应字符串标号 -> 行

                // 遍历所有的行，检查是否有相同的字符串对
                for (int k = 0; k < n && isPNF; k++)
                {
                    if (pos.find({table[k][i], table[k][j]}) == pos.end())
                        pos[{table[k][i], table[k][j]}] = k;
                    else
                    {
                        printf("NO\n%d %d\n%d %d\n", pos[{table[k][i], table[k][j]}]+1, k+1, i+1, j+1);
                        isPNF = false;
                    }
                }
            }
        }
        if (isPNF) printf("YES\n");
    }
    return 0;
}