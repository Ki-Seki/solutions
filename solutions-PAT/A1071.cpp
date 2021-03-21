/*
 * hint:
 * <map> 使用红黑树实现，因此会自动将字符串按字典序升序排序
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

map <string, int> word_cnt;

bool is_valid(char c)
{
    if ('a' <= c && c <= 'z') return true;
    if ('0' <= c && c <= '9') return true;
    if ('A' <= c && c <= 'Z') return true;
    return false;
}

int main()
{
    string line;
    getline(cin, line);

    // fill the map of word_cnt
    for (int i = 0; i < line.length(); i++)
    {
        string word = "";
        while (i < line.length() && is_valid(line[i]))
        {
            if ('A' <= line[i] && line[i] <= 'Z')
                line[i] += 32;
            word += line[i];
            i++;
        }
        if (word != "")
        {
            if (word_cnt.find(word) != word_cnt.end())
                word_cnt[word]++;
            else
                word_cnt[word] = 1;
        }
    }

    // get ans
    string ans;
    int max = 0;
    for (map <string, int>::iterator it = word_cnt.begin(); it != word_cnt.end(); it++)
        if (it->second > max)
        {
            ans = it->first;
            max = it->second;
        }
    cout << ans << ' ' << max;
    return 0;
}