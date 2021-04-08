/*
 * hint:
 * 出栈入栈产生的序列数符合 卡特兰数
 * 这个序列前 15 个值为：
 * 1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440
*/
#include <cstdio>

// cnt: 栈内元素数
// to_push: 剩余入栈机会
// to_pop: 剩余出栈机会
int dfs(int cnt, int to_push, int to_pop)
{
    // 递归边界
    if (to_pop == 0)
        return 1;
    
    int ans = 0;
    // 岔路口一：入栈一个元素
    if (to_push > 0)
        ans += dfs(cnt + 1, to_push - 1, to_pop);
    // 岔路口二：出栈一个元素
    if (to_pop > 0 && cnt > 0)
        ans += dfs(cnt - 1, to_push, to_pop - 1);
    return ans;
}

// void generate_catalan_numbers()
// {
//     for (int i = 0; i < 15; i++)
//         printf("%d ", dfs(0, i, i));
//     printf("\n");
// }

int main()
{
    // generate_catalan_numbers();
    int n;
    scanf("%d", &n);
    printf("%d", dfs(0, n, n));
    return 0;
}