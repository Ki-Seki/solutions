#include <iostream>
#define MAXN 1005
using namespace std;

struct {
    int exp;
    double coe;
} poly[MAXN];

double ans[MAXN * 2] = {0};

int main()
{
    int k1, k2, exp;
    double coe;
    // read in the first polynomial
    cin >> k1;
    for (int i = 0; i < k1; i++)
        scanf("%d %lf", &poly[i].exp, &poly[i].coe);
    // read in the second one and calculate meanwhile
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        scanf("%d %lf", &exp, &coe);
        for (int j = 0; j < k1; j++)
            ans[exp + poly[j].exp] += coe * poly[j].coe;
    }
    // calculate count
    int count = 0;
    for (int i = 0; i < MAXN *2; i++) if (ans[i] != 0) count++;
    // output
    printf("%d", count);
    for (int i = MAXN * 2 - 1; i >= 0; i--)
        if (ans[i] != 0)
            printf(" %d %.1lf", i, ans[i]);
    return 0;
}