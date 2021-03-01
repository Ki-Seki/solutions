#include <iostream>
#include <cstring>
#define MAX 85
using namespace std;

char str[MAX], graph[MAX/2][MAX/2];

int main()
{
    // init
    scanf("%s", str);
    int N=strlen(str), n1=(N+2)/3, n2=N+2-2*n1;
    for (int i = 0; i < MAX / 2; i++)
        for (int j = 0; j < MAX / 2; j++)
            graph[i][j] = ' ';
    
    // convert
    int pos = 0;
    for (int i = 1; i <= n1; i++) graph[i][1] = str[pos++];  // first stroke
    for (int i = 2; i <= n2; i++) graph[n1][i] = str[pos++];  // second stroke
    for (int i = n1 - 1; i >= 1; i--) graph[i][n2] = str[pos++];  // third stroke

    // output
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++) printf("%c", graph[i][j]);
        printf(i == n1 ? "" : "\n");
    }
    return 0;
}