// 方法一：递归

#include <bits/stdc++.h>
using namespace std;

bool is_death(int i, int j, int n)
{
    if (n == 2)
        if (i == 0 && j == 0) return 0;
        else return 1;

    if (i < n / 2 && j < n / 2) return 0;
    else if (i < n/2 && j >= n/2) return is_death(i, j-n/2, n/2);
    else if (i >= n/2 && j < n/2) return is_death(i-n/2, j, n/2);
    else return is_death(i-n/2, j-n/2, n/2);
}

int main()
{
    int n;
    scanf("%d", &n);
    n = int(pow(2, n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", is_death(i, j, n));
        printf("\n");
    }
    return 0;
}

// 方法二：打表法，一个 1024×1024 的表