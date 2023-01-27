#include <bits/stdc++.h>
#define MAXLEN 40
using namespace std;
typedef long long LL;

char ops[4] = "+-*";
char line[MAXLEN];
char formula[MAXLEN] = "";
char op;
int kase;
LL n1, n2, ans;

LL cal(LL n1, char op, LL n2)
{
    switch (op)
    {
        case 'a':
            return n1 + n2;
        case 'b':
            return n1 - n2;
        case 'c':
            return n1 * n2;
        default:
            return -1;
    }
}

int main()
{
    scanf("%d\n", &kase);
    for (int i = 0; i < kase; i++)
    {
        cin.getline(line, MAXLEN);
        if (line[0] == 'a' || line[0] == 'b' || line[0] == 'c')
            sscanf(line, "%c%lld%lld", &op, &n1, &n2);
        else
            sscanf(line, "%lld%lld", &n1, &n2);
        ans = cal(n1, op, n2);
        sprintf(formula, "%lld%c%lld=%lld", n1, ops[op-'a'], n2, ans);
        printf("%s\n%d\n", formula, strlen(formula));
    }
    return 0;
}