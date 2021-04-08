#include <cstdio>
#include <vector>
#define MAXN 22

using namespace std;

int n, k;
int numbers[MAXN];
bool is_existed[MAXN] = {};
vector<int> ans;

int sum()
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += ans[i];
    return sum;
}

bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// index: 正在考察的元素下标
// now_cnt: 当前 ans 数组中已有元素数
int dfs(int index, int now_cnt)
{
    // 递归边界
    if (now_cnt == k)
        return is_prime(sum()) ? 1 : 0;
    if (index >= n)
        return 0;

    int result = 0;
    // 岔路口一：选择 index
    if (!is_existed[index])
    {
        ans.push_back(numbers[index]);
        is_existed[index] = true;
        result += dfs(index + 1, now_cnt + 1);
        ans.pop_back();
        is_existed[index] = false;
    }
    // 岔路口二：不选 index
    result += dfs(index + 1, now_cnt);
    return result;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
    printf("%d", dfs(0, 0));
    return 0;
}