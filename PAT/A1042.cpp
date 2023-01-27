#include <iostream>
#include <cstring>
#define CAPACITY 54
using namespace std;

int main()
{

    int k, perm[CAPACITY + 1], shuffled[CAPACITY + 1];
    char mp[5] = {'S', 'H', 'C', 'D', 'J'};
    // input
    cin >> k;
    for (int i = 1; i <= CAPACITY; i++) cin >> perm[i];
    // initialize
    for (int i = 1; i <= CAPACITY; i++) shuffled[i] = i;
    // stimulate
    for (int i = 0; i < k; i++)
    {
        int tmp[CAPACITY + 1];
        for (int j = 1; j <= CAPACITY; j++)
            tmp[perm[j]] = shuffled[j];
        memcpy(shuffled, tmp, sizeof(tmp));
    }
    // output
    for (int i = 1; i <= CAPACITY; i++)
        printf((i == CAPACITY)? "%c%d" : "%c%d ", 
            mp[(shuffled[i]-1)/13], (shuffled[i]-1)%13+1);
    return 0;
}