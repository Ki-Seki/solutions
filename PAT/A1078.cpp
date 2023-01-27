#include <iostream>
#include <cmath>
#define MAXN 10005

bool hash_table[MAXN] = {false};

bool is_prime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= (int) sqrt(n * 1.0); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int table_size, n;
    scanf("%d %d", &table_size, &n);
    while (is_prime(table_size) == false) table_size++;
    bool first_output = true;
    for (int i = 0; i < n; i++)
    {
        int ele, pos = -1;
        scanf("%d", &ele);

        // find hash position
        if (hash_table[ele % table_size] == false)
        {
            pos = ele % table_size;
            hash_table[pos] = true;
        }
        else  // 正向平方探测
        {
            for (int i = 1; i < table_size; i++)
                if (hash_table[(ele + i * i) % table_size] == false)
                {
                    pos = (ele + i * i) % table_size;
                    hash_table[pos] = true;
                    break;
                }
        }

        // output
        if (pos != -1)
            if (first_output)
                printf("%d", pos), first_output = false;
            else
                printf(" %d", pos);
        else
            printf(" -");
    }
    return 0;
}