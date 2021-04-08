/*
 * hint:
 * 本题采用三种方法，前两种没有使用递归，为网友答案，第三种使用递归
 * 
 * 方法一：使用进位思想
 * 方法二：使用栈模拟 dfs
 * 方法三：使用普通递归的 dfs
*/

// // 方法一：使用进位的思想，从初始序列 12...n 开始，视其为特殊进制的数字，逐步加一
// #include <cstdio>

// int main()
// {
//     bool end = 0;
//     int n = 0, r = 0, sum = 0, a[25] = {0};
//     while (scanf("%d", &n) == 1)
//     {
//         scanf("%d", &r);
//         end = 0;
//         for (int i = 1; i <= r; i++)  // 初始化为第一个序列
//             a[i] = i;
//         while (!end)
//         {
//             for (int i = 1; i <= r; i++)
//                 printf("%d%c", a[i], i == r ? '\n' : ' ');
//             int flag = r;  // 指示现在访问的元素
//             a[r]++;  // 为下一个排列做进位准备
//             while (1)
//             {
//                 if (flag == 0)  // 访问到 0，意味着已经找完所有排列
//                 {
//                     end = 1;
//                     break;
//                 }

//                 if (r - flag > n - a[flag])  // r - flag 指示空位数，n - a[flag] 指示空余元素数，若大于，则此位置可进位
//                     a[flag - 1]++;
//                 else
//                 {
//                     for (int i = flag + 1; i <= n; i++)
//                         a[i] = a[i - 1] + 1;
//                     break;
//                 }
//                 flag--;
//             }
//         }
//     }
//     return 0;
// }

// // 方法二：完全利用栈来模拟 dfs
// #include <cstdio>
// #include <stack>
// #include <vector>

// using namespace std;

// vector<int> vec;  // 模拟输出的序列暂存数组
// stack<int> s;  // 存储是否已经在 vec 中
// int n, r;

// void DFS(int index)
// {
//     s.push(index);
//     vec.push_back(index);
//     int x;
//     bool popFlag = false;  // 标记是否需要弹出元素
//     while (!s.empty())
//     {
//         if (vec.size() == r)  // 已满，可输出
//         {
//             for (int i = 0; i < r; i++)
//                 printf(i == r - 1 ? "%d\n" : "%d ", vec[i]);
//             popFlag = true;
//         }
//         x = s.top();  // 一直保存着栈顶元素
//         if (x == n)  // 意味着要弹出了
//         {
//             s.pop();
//             vec.pop_back();
//             popFlag = true;
//             continue;
//         }
//         if (popFlag == true)
//         {
//             s.pop();
//             vec.pop_back();
//             popFlag = false;
//         }
//         if (x < n)
//         {
//             s.push(x + 1);
//             vec.push_back(x + 1);
//         }
//     }
// }

// int main()
// {
//     scanf("%d %d", &n, &r);
//     DFS(1);
// }

// 方法三：dfs
#include <cstdio>
#include <vector>
#define MAXN 22

using namespace std;

int n, r;
vector <int> ans;
bool is_existed[MAXN] = {false};

// index：待考察元素
// now_cnt：已进入 ans 序列的元素个数
void dfs(int index, int now_cnt)
{
    if (now_cnt == r)
    {
        for (int i = 0; i < r; i++)
            printf(i == r - 1 ? "%d\n" : "%d ", ans[i]);
        return;
    }
    for (int i = index; i <= n; i++)
    {
        if (!is_existed[i])
        {
            is_existed[i] = true;
            ans.push_back(i);
            dfs(i + 1, now_cnt + 1);
        }
        is_existed[i] = false;
        ans.pop_back();
    }

}

int main()
{
    scanf("%d %d", &n, &r);
    dfs(1, 0);
    return 0;
}