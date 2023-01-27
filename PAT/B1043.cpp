#include <iostream>
using namespace std;

int hash_table[6] = {};
char mp[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main()
{
    char c;
    int cnt = 0;
    while (scanf("%c", &c) != EOF)
    {
        int i = 0;
        for (i = 0; i < 6; i++)
            if (mp[i] == c)
                break;
        if (i < 6)
        {
            hash_table[i]++;
            cnt++;
        }
    }
    int i = 0;
    while (cnt > 0)
    {
        if (hash_table[i] > 0)
        {
            printf("%c", mp[i]);
            hash_table[i]--;
            cnt--;
        }
        i = (i + 1) % 6;
    }
    return 0;
}