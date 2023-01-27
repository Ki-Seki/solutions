/*
 * hint:
 * 
 * 此题使用两种解法
 * 1. 打表法：无法通过因为代码长度超过限制，仅表的大小就超过 130KB
 * 2. 正常的筛法模拟求解
 * 
 * 启示：打表前思考表是否会太大
*/

#include <iostream>
// #include <map>
// using namespace std;
#define MAXN 100000  // the primes to be found at most not over MAXN

bool not_prime[MAXN + 10] = {};
int primes[MAXN / 10 * 4], len_primes = 0;

// find primes below or equal to n
void find_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (not_prime[i] == false)
        {
            primes[len_primes++] = i;
            for (int j = i + i; j <= n; j += i)
                not_prime[j] = true;
        }
    }
}

// // 打表法

// // 制表脚本 表结构为字典类型。
// void get_ans_table()
// {
//     int acc = 0;  // 累计素数对个数
//     for (int i = 1; i < len_primes; i++)
//     {
//         if (primes[i] - primes[i - 1] == 2) acc += 1;
//         printf("{%d, %d}, ", primes[i], acc);
//     }
// }
// // 调用此函数即可解题
// void use_ans_table()
// {
//     map <int, int> ans_table = {/* 制表脚本的值粘贴到此处 */};
//     int n;
//     scanf("%d", &n);
//     for (int i = n; i >= 0; i--)
//         if (ans_table.count(i) > 0)
//         {
//             printf("%d", ans_table[i]);
//             return;
//         }
// }

// main() 函数内即为正常的方法
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    find_primes(n);
    for (int i = 1; i < len_primes; i++)
        if (primes[i] - primes[i - 1] == 2)
            ans++;
    printf("%d", ans);
    return 0;
}