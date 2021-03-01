#include <iostream>
#include <algorithm>
#define MAX_N 105
#define MAX_K 105
using namespace std;

bool isCovered[MAX_N] = {};
int arr[MAX_K] = {};

int main()
{
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
        n = arr[i];
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3 * n + 1) / 2;
            if (n < MAX_N)
                isCovered[n] = true;
        }
    }
    sort(arr, arr + k);
    bool isFirstOutput = true;
    for (int i = k - 1; i >= 0; i--)
        if (! isCovered[arr[i]])
        {
            if (isFirstOutput)
            {
                printf("%d", arr[i]);
                isFirstOutput = false;
            }
            else printf(" %d", arr[i]);
        }
    return 0;
}