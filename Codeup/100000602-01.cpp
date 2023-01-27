#include <stack>
#include <string>
#include <iostream>
#include <map>

using namespace std;

map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}, };

bool is_matched(const string& l)
{
    stack<char> brackets;
    for (int i = 0; i < l.length(); i++)
        if (l[i] == '(' || l[i] == '[' || l[i] == '{')
            brackets.push(l[i]);
        else if (l[i] == ')' || l[i] == ']' || l[i] == '}')
        {
            if (!brackets.empty() && match[l[i]] == brackets.top())
                brackets.pop();
            else
                return false;
        }
    if (brackets.empty()) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n; getchar();
    while (n--)
    {
        string line;
        getline(cin, line);
        if (is_matched(line)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}