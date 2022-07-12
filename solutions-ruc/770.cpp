#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int k;

int main()
{
    cin >> s1 >> s2 >> k;

    for (int i = 0; i < s2.length() - s1.length(); i++)
    {
        int acc = 0;
        for (int j = 0; j < s1.length(); j++)
        {
            if (s2[i] != s1[j]) acc++;
            if (acc > k) break;
        }
        if (acc <= k)
        {
            printf("%d %d\n", i, i + s1.length() - 1);
            for (int k = i; k < i + s1.length(); k++)
                printf("%c", s1[k]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}