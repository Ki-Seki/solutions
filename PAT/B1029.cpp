/*
 * hint:
 * 常见字符及其 ASCII 码 {'0': 48, '9': 57, 'A': 65, 'Z': 90, '_': 95, 'a': 97, 'z': 122}
*/
#include <iostream>
#include <cstring>
#define MAX_LEN 85
#define MAX_ASCII 130 // python: ord('z') == 122
using namespace std;

// 0 denote ele. never exists, 
// 1 denote ele. should be output, 
// 2 denote ele. actually output
int hash_table[MAX_ASCII] = {};

int my_hash(char c)
{
    if ('a' <= c && c <= 'z') return c - 'a' + 'A';
    else return c;
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    scanf("%s\n%s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
        hash_table[my_hash(str1[i])] = 1;
    for (int i = 0; i < len2; i++)
        hash_table[my_hash(str2[i])] = 2;
    for (int i = 0; i < len1; i++)
        if (hash_table[my_hash(str1[i])] == 1)
        {
            printf("%c", my_hash(str1[i]));
            hash_table[my_hash(str1[i])] = 2;
        }
            
    return 0;
}