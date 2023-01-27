#include <iostream>
using namespace std;

int main()
{
    int cnt[10] = {0};
    char ch;
    while (scanf("%c", &ch) != EOF)
        cnt[ch-'0']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i]) printf("%d:%d\n", i, cnt[i]);
    return 0;
}