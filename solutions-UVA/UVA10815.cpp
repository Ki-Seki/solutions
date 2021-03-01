#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string line;
    set<string> dict;
    while (cin >> line)
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (isalpha(line[i])) line[i] = tolower(line[i]);
            else if (isblank(line[i])) ;
            else line[i] = ' ';
        }
        stringstream ss(line);
        string tmp;
        while (ss >> tmp)
        {
            dict.insert(tmp);
        }
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        cout << *it << endl;
    }
    
    return 0;
}