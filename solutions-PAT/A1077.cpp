#include <iostream>
#include <cstring>
// #include <cstdio>
#include <algorithm>
#define MAXN 1005
#define MAXSIZE 260
using namespace std;

char words[MAXN][MAXSIZE];

int main()
{
    int n, minLen = MAXSIZE;
    cin >> n;
    getchar();  // get rid of the '\n'
    for (int i = 0; i < n; i++)
    {
        // gets(words[i]);  // PAT not supports gets()
        cin.getline(words[i], MAXSIZE);
        int len = strlen(words[i]);
        if (len <= minLen) minLen = len;
        reverse(words[i], words[i] + len);
    }
    int cnt = 0;
    for (int i = 0; i < minLen; i++)
    {
        bool consistent = true;
        char ch = words[0][i];
        for (int j = 1; j < n; j++)
        {
            if (ch != words[j][i])
            {
                consistent = false;
                break;
            }
        }
        if (consistent) cnt++;
        else break;
    }

    if (cnt)
    {
        for (int i = cnt - 1; i >= 0; i--)
            printf("%c", words[0][i]);
        printf("\n");
    }
    else 
        printf("nai\n");
    return 0;
}