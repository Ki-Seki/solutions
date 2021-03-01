#include <iostream>
#define MAX_LEN 26
using namespace std;

int hash_table[MAX_LEN] = {};

int my_hash(char c)
{
    if ('A' <= c && c <= 'Z') return c - 'A';
    else if ('a' <= c && c <= 'z') return c - 'a';
    else return -1;
}

int main()
{
    char tmp;
    int max_index = 0, h;
    while (scanf("%c", &tmp) != EOF)
    {
        h = my_hash(tmp);
        if (h != -1)
        {
            hash_table[h]++;
            if (hash_table[h] > hash_table[max_index])
                max_index = h;
            else if (hash_table[h] == hash_table[max_index] && h < max_index)
                max_index = h;
        }
    }
    printf("%c %d", max_index + 'a', hash_table[max_index]);
    return 0;
}