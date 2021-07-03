/*
 * hint:
 * 测试点2：考察对第一个字符串的正确读取，题中未说明第一个字符串不含空格
*/
#include <iostream>
#include <cstring>
#define MAX_LEN 100005
#define MAX_ASCII 256
using namespace std;

bool isBroken[MAX_ASCII] = {};

int my_hash(char c)
{
    if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    cin.getline(str1, MAX_LEN);
    cin.getline(str2, MAX_LEN);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
        isBroken[my_hash(str1[i])] = true;
    for (int i = 0; i < len2; i++)
        if (isBroken[my_hash(str2[i])])
            continue;
        else if ('A' <= str2[i] && str2[i] <= 'Z' && isBroken[my_hash('+')])
            continue;
        else
            printf("%c", str2[i]);
    printf("\n");
    return 0;
}