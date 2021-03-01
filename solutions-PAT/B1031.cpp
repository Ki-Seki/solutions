#include <iostream>
using namespace std;

const int m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'},
w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

bool isCorrect(char id[])
{
    int check_sum = 0, z;
    for (int j = 0; j < 17; j++)
    {
        if (id[j] < '0' || id[j] > '9') return false;
        check_sum += w[j] * (id[j] - '0');
    }
    z = check_sum % 11;
    if (m[z] != id[17]) return false;
    return true;
}

int main()
{
    bool isAllCorrect = true;
    char id[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", id);
        if (!isCorrect(id))
            printf("%s\n", id), isAllCorrect = false;
    }
    if (isAllCorrect) printf("All passed\n");
    return 0;
}