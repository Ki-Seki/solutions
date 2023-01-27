#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char line[7];
    while (cin.getline(line, 7))
    {
        if (line == "") break;
        int len = strlen(line);
        do {
            printf("%s\n", line);
        } while (next_permutation(line, line + len));
        printf("\n");
    }
    return 0;
}