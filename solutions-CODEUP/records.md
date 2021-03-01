> ps. "xxxxxxxxx-yy" refers to a problem whose cid = xxxxxxxxx and pid = yy

# 100000583-00 吃糖果

code:

```c++
#include <iostream>
using namespace std;

int candy(int cnt)
{
    if (cnt == 1)
        return 1;
    else if (cnt == 2)
        return 2;
    else
        return candy(cnt - 1) + candy(cnt - 2);
}

int main()
{
    int n;
    while (cin >> n)
        cout << candy(n) << endl;
    return 0;
}
```

# 100000583-03 八皇后

code:

```c++
/*  未优化的方法
#include <iostream>
#include <algorithm>
using namespace std;

const int n = 8;  // 8 阶全排列

int p[n + 2], ans[100][n + 2], pos = 1;
bool exist[n + 2] = {};

int perm(int index)
{
    if (index == n + 1)  // 递归边界
    {
        bool isValid = true;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (abs(i - j) == abs(p[i] - p[j]))  // 横纵差相等即在同一斜线
                {
                    isValid = false;
                    break;
                }
        if (isValid)
        {
            for (int i = 1; i <= n; i++)
                ans[pos][i] = p[i];
            pos++;
        }
    }
    else
        for (int x = 1; x <= n; x++)  // 枚举 1 ~ n 所有 x
            if (! exist[x])  // 若 x 未被使用，填在 p[index]
            {
                p[index] = x;
                exist[x] = true;
                perm(index + 1);
                exist[x] = false;
            }
}

int main()
{
    perm(1);
    int tmp;
    scanf("%d", &tmp);
    while(scanf("%d", &tmp) != EOF)
        for (int i = 1; i <= 8; i++)
            printf(i == 8 ? "%d\n" : "%d", ans[tmp][i]);

    return 0;
}
*/

// 事与愿违，优化后的性能并无提升，反而降低
#include <iostream>
#define N 8  // 8 阶全排列
#define SOLVE 92  // 共 92 个解
using namespace std;

int p[N + 2], ans[SOLVE + 10][N + 2], pos = 1;
bool exist[N + 2] = {};

// 现在正在为 p[index] 找合适的值
// cnt 是需要的的合法的八皇后位置的个数
void perm(int index, int cnt)
{
    if (pos > cnt)  // 递归边界：当已经找到足够合法的八皇后位置
        return;
    if (index == N + 1)  // 递归边界：当找到一个合法的八皇后位置
    {
        for (int i = 1; i <= N; i++)  // 保存到 ans 数组
            ans[pos][i] = p[i];
        pos++;
        return;
    }

    // 递归式
    for (int x = 1; x <= N; x++)  // 枚举 1 ~ n 所有 x
        if (! exist[x])  // 若 x 未被使用，填在 p[index]
        {
            // 回溯：若非合法位置，枚举下一个 x
            bool isValid = true;
            for (int i = 1; i < index; i++)
                if (abs(i - index) == abs(p[i] - x))
                {
                    isValid = false;
                    break;
                }
            if (! isValid) continue;

            p[index] = x;
            exist[x] = true;
            perm(index + 1, cnt);
            exist[x] = false;
        }
    return;
}

int main()
{
    int n, b[SOLVE + 100], max_b = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] > max_b)
            max_b = b[i];
    }
    perm(1, max_b);
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= N; j++)
            printf(j == N ? "%d\n" : "%d", ans[b[i]][j]);
    return 0;
}
```

# 100000583-02 神奇的口袋

hint:

`递归题的关键就是找清楚 递归边界 和 递归式`

code:

```c++
#include <iostream>
#define MAXN 25
using namespace std;

const int capacity = 40;
int things[MAXN], cnt;

// 决策是否选择 things[index]
// 当前重量为 curr_weight
int choice(int index, int curr_weight)
{
    // 递归边界
    if (curr_weight == capacity)
        return 1;
    if (index > cnt || curr_weight > capacity)
        return 0;

    // 递归式
    return choice(index + 1, curr_weight + things[index]) + choice(index + 1, curr_weight);
}

int main()
{
    while (scanf("%d", &cnt) != EOF)
    {
        for (int i = 1; i <= cnt; i++)
            scanf("%d", &things[i]);
        printf("%d\n", choice(1, 0));
    }
    return 0;
}
```

# 100000583-01 数列

code:

```c++
#include <iostream>
#define MAXN 25
using namespace std;

int fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int j = 1; j <= m; j++)
        {
            int doubleSpace = m - j, cnt = j * 2 - 1;
            for (int k = 0; k < doubleSpace; k++)
                printf("  ");
            for (int k = 0; k < cnt; k++)
                printf(k == cnt -1 ? "%d\n" : "%d ", fib[k]);
        }
    }
    return 0;
}
```

# 100000587-00 求第k大的数

hint:

`随机选择算法的实践，本质上是一种优化的查询。不存在特定值使其达到 O(n^2)；平均 O(n)`

code:

```c++
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAXN 10
using namespace std;

unsigned array[MAXN];

// 双指针方法的分割函数的另一种写法
// decreasingly partition the array in [left, right]
int randPartition(int left, int right)
{
    int p = rand() % (right - left) + left;
    swap(array[p], array[left]);

    int prime = left++;  // 主元为初始的 left 值，left 值 然后向后位移一位
    while (left < right)  // until left == right
    {
        while (left < right && array[left] >= array[prime]) left++;
        while (left < right && array[right] < array[prime]) right--;
        swap(array[left], array[right]);
    }
    swap(array[prime], array[left - 1]);  // 交换主元到中间
    return left - 1;
}

// random selection algorithm 随机选择算法
// find the k-th biggest number in [left, right], guarantee left != right
unsigned find_no_k(int left, int right, int k)
{
    if (left == right && k == 1)
        return array[left];
    int pos = randPartition(left, right);
    if (pos + 1 == k)
        return array[pos];
    else if (pos + 1 < k)
        return find_no_k(pos + 1, right, k - pos - 1);
    else
        return find_no_k(left, pos - 1, k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("%d", find_no_k(0, n - 1, k));
    return 0;
}
```

# 100000589-00 Least Common Multiple

code:

```c++
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return (!b ? a : gcd(b, a%b));
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int n, m, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ans = 1;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            ans = lcm(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
```

# 100000583-00 模板

hint:

1. ``

2. ``

code:

```c++

```

