#include <cstdio>
#include <algorithm>
#define MAX 150

int A, N;
int den[10];

int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a%b);
}

bool is_ok(int obj)
{
    int n = 0, d = 1;
    for (int i = 0; i < N; i++)
        if (den[i])
        {
            n = n * den[i] + d;
            d = d * den[i];
            int g = gcd(n, d);
            n /= g;
            d /= g;
        }
    return n == 1 && d == obj;
}

void output()
{
    printf("%d", den[0]);
    for (int i = 1; i < N; i++) printf(" %d", den[i]);
}

int main()
{
    scanf("%d %d", &A, &N);
    if (N == 2)
    {
        for (den[0] = A+1; den[0] <= MAX; den[0]++)
        for (den[1] = den[1]+1; den[1] <= MAX; den[1]++)
        if (is_ok(A)) {output(); return 0;}
    }
    if (N == 3)
    {
        for (den[0] = A+1; den[0] <= MAX; den[0]++)
        for (den[1] = den[0]+1; den[1] <= MAX; den[1]++)
        for (den[2] = den[1]+1; den[2] <= MAX; den[2]++)
        if (is_ok(A)) {output(); return 0;}
    }
    if (N == 4)
    {
        for (den[0] = A+1; den[0] <= MAX; den[0]++)
        for (den[1] = den[0]+1; den[1] <= MAX; den[1]++)
        for (den[2] = den[1]+1; den[2] <= MAX; den[2]++)
        for (den[3] = den[2]+1; den[3] <= MAX; den[3]++)
        if (is_ok(A)) {output(); return 0;}
    }
    if (N == 5)
    {
        for (den[0] = A*2; den[0] <= MAX; den[0]++)
        for (den[1] = den[0]+1; den[1] <= MAX; den[1]++)
        for (den[2] = den[1]+1; den[2] <= MAX; den[2]++)
        for (den[3] = den[2]+1; den[3] <= MAX; den[3]++)
        for (den[4] = den[3]+1; den[4] <= MAX; den[4]++)
        if (is_ok(A)) {output(); return 0;}
    }
    
    return 0;
}