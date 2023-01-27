#include <iostream>
#define MAX_GRAGE 105
using namespace std;

int hash_table[MAX_GRAGE] = {};

int main()
{
    int n, tmp, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        hash_table[tmp]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &tmp);
        printf(i == k - 1 ? "%d" : "%d ", hash_table[tmp]);
    }
    return 0;
}