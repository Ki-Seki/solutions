#include <iostream>
#define MAX_N 100005
#define MAX_NUMBER 10005
using namespace std;

int hash_table[MAX_NUMBER] = {}, arr[MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        hash_table[arr[i]]++;
    }
    int pos = 0;
    for (; pos < n; pos++)
        if (hash_table[arr[pos]] == 1)
            break;
    if (pos < n)
        printf("%d", arr[pos]);
    else
        printf("None");
    return 0;
}