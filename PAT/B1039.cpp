#include <iostream>
#include <cstring>
#define MAX_ASCII 260
#define MAX_LEN 1005
using namespace std;

int mp_sale[MAX_ASCII] = {}, mp_want[MAX_ASCII] = {};

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    cin.getline(str1, MAX_LEN);
    cin.getline(str2, MAX_LEN);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
        mp_sale[str1[i]]++;
    for (int i = 0; i < len2; i++)
        mp_want[str2[i]]++;
    int surplus = 0, deficit = 0;
    for (int i = 0; i < MAX_ASCII; i++)
        if (mp_sale[i] > mp_want[i])
            surplus += mp_sale[i] - mp_want[i];
        else
            deficit += mp_want[i] - mp_sale[i];
    if (deficit <= 0)
        printf("Yes %d", surplus);
    else
        printf("No %d", deficit);
    return 0;
}