/*
 * hint:
 * 综合运用了多个 STL
*/
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool is_num(char c)
{
    return ('0' <= c && c <= '9');
}

void parse_a_line(vector<int>& nums, const string& line)
{
    for (int j = 0; j < line.length(); j++)
    {
        int tmp = 0;
        bool found_num = false;
        while (j < line.length() && is_num(line[j]))
        {
            found_num = true;
            tmp = tmp * 10 + line[j] - '0';
            j++;
        }
        if (found_num) nums.push_back(tmp);
    }
}

struct cmp
{
    bool operator () (pair<int, int> a, pair<int, int> b)
    {
        if (a.second != b.second) return a.second < b.second;
        else return a.first > b.first;
    }
};

int main()
{
    int n;
    while (cin >> n)  // for each case
    {
        getchar();  // clear '\n'

        // get task - priority
        map<int, int> task_priority;
        for (int i = 0; i < n; i++)  // for each line
        {
            string line;
            getline(cin, line);
            vector<int> nums_in_a_line;
            parse_a_line(nums_in_a_line, line);
            if (task_priority.find(nums_in_a_line[0]) == task_priority.end())
                task_priority[nums_in_a_line[0]] = n;
            for (int i = 1; i < nums_in_a_line.size(); i++)
                task_priority[nums_in_a_line[i]] = task_priority[nums_in_a_line[0]] - 1;
        }

        // use priority_queue to output ans
        priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> ans;
        for (map<int, int>::iterator it = task_priority.begin(); it != task_priority.end(); it++)
            ans.push(make_pair(it->first, it->second));

        // output ans
        while (ans.size())
        {
            printf("Task%d ", ans.top().first);
            ans.pop();
        }
    }
    return 0;
}