#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char line[201];
    while (cin.getline(line, 201))
    {
        if (line == "") break;
        int len = strlen(line);
        reverse(line, line + len);
        printf("%s\n", line);
    }
    return 0;
}