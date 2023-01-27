#include <iostream>
#include <cstring>
#define MAX_ASCII 260
#define MAX_LEN 10005
using namespace std;

bool hash_table[MAX_ASCII] = {};
char s1[MAX_LEN], s2[MAX_LEN];

int main()
{
    cin.getline(s1, MAX_LEN);
    cin.getline(s2, MAX_LEN);
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < l2; i++)
        hash_table[s2[i]] = true;
    for (int i = 0; i < l1; i++)
    {
        if (! hash_table[s1[i]])
            printf("%c", s1[i]);
    }
    return 0;
}