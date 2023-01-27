#include <cstring>
#include <cstdio>
#include <iostream>
#define MAXN 10
using namespace std;
char s[MAXN], pattern[MAXN];

int index(char* s, char* t)
{
    int i = 1, j = 1, ls = strlen(s), lt = strlen(t);
    while (i <= ls && j <= lt)
    {
        if (s[i] == t[j])
        {
            i++; j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > lt) return i - lt;
    else return 0;
}

int main()
{
    cin >> s+1 >> pattern+1;
    cout << index(s, pattern);
    return 0;
}