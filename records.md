# B1024 科学计数法

hint:

`变量声明的原则：哪里需要，哪里声明`

code:

```c++
#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;

int main()
{
    char num[MAX], sign;
    scanf("%c%s", &sign, num);

    // find 'E'
    int len = strlen(num), pos;
    for (int i = 0; i < len; i++)
        if (num[i] == 'E')
        {
            pos = i;
            break;
        }

    // calculate the absoulte exp, i.e., without sign
    int exp = 0;
    for (int i = pos + 2; i < len; i++)
        exp = exp * 10 + num[i] - '0';

    // output
    if (sign == '-') printf("-");
    if (num[pos+1] == '-')
    {
        // special judge when the exp == 0
        if (exp == 0)  
            for (int i = 1; i < pos; i++)
                printf("%c", num[i]);
        else
        {
            // output zeros with count of exp
            printf("0.");
            for (int i = 0; i < exp - 1; i++) printf("0");
            // output the rest
            printf("%c", num[0]);
            for (int i = 2; i < pos; i++) printf("%c", num[i]);
        }

    }
    else
    {
        if (pos - 2 > exp)  // no need to append zeros
        {
            printf("%c", num[0]);
            for (int i = 2; i < 2 + exp; i++) printf("%c", num[i]);
            printf(".");
            for (int i = 2 + exp; i < pos; i++) printf("%c", num[i]);
        }
        else  // contains that to append no zero
        {
            int zeros = exp - (pos - 2);
            printf("%c", num[0]);
            for (int i = 2; i < pos; i++) printf("%c", num[i]);
            for (int i = 0; i < zeros; i++) printf("0");  // print zeros
        }
    }
    return 0;
}
```

# B1029 旧键盘

hint:

`常见字符及其 ASCII 码 {'0': 48, '9': 57, 'A': 65, 'Z': 90, '_': 95, 'a': 97, 'z': 122}`

code:

```c++
#include <iostream>
#include <cstring>
#define MAX_LEN 85
#define MAX_ASCII 130 // python: ord('z') == 122
using namespace std;

// 0 denote ele. never exists, 
// 1 denote ele. should be output, 
// 2 denote ele. actually output
int hash_table[MAX_ASCII] = {};

int my_hash(char c)
{
    if ('a' <= c && c <= 'z') return c - 'a' + 'A';
    else return c;
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    scanf("%s\n%s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
        hash_table[my_hash(str1[i])] = 1;
    for (int i = 0; i < len2; i++)
        hash_table[my_hash(str2[i])] = 2;
    for (int i = 0; i < len1; i++)
        if (hash_table[my_hash(str1[i])] == 1)
        {
            printf("%c", my_hash(str1[i]));
            hash_table[my_hash(str1[i])] = 2;
        }
            
    return 0;
}
```

# B1033 旧键盘打字

hint:

`测试点2：考察对第一个字符串的正确读取，题中未说明第一个字符串不含空格`

code:

```c++
#include <iostream>
#include <cstring>
#define MAX_LEN 100005
#define MAX_ASCII 256
using namespace std;

bool isBroken[MAX_ASCII] = {};

int my_hash(char c)
{
    if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
    cin.getline(str1, MAX_LEN);
    cin.getline(str2, MAX_LEN);
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
        isBroken[my_hash(str1[i])] = true;
    for (int i = 0; i < len2; i++)
        if (isBroken[my_hash(str2[i])])
            continue;
        else if ('A' <= str2[i] && str2[i] <= 'Z' && isBroken[my_hash('+')])
            continue;
        else
            printf("%c", str2[i]);
    printf("\n");
    return 0;
}
```

# B1042 字符统计

hint:

`测试点2：考察了存在并列时的处理，即要考虑并列时输出字母序小的`

code:

```c++
#include <iostream>
#define MAX_LEN 26
using namespace std;

int hash_table[MAX_LEN] = {};

int my_hash(char c)
{
    if ('A' <= c && c <= 'Z') return c - 'A';
    else if ('a' <= c && c <= 'z') return c - 'a';
    else return -1;
}

int main()
{
    char tmp;
    int max_index = 0, h;
    while (scanf("%c", &tmp) != EOF)
    {
        h = my_hash(tmp);
        if (h != -1)
        {
            hash_table[h]++;
            if (hash_table[h] > hash_table[max_index])
                max_index = h;
            else if (hash_table[h] == hash_table[max_index] && h < max_index)
                max_index = h;
        }
    }
    printf("%c %d", max_index + 'a', hash_table[max_index]);
    return 0;
}
```

# B1030 完美数列

hint:

1. `测试点1，5：考察当完美序列长度恰是 N 的情况`

2. `sort 默认升序排列`

3. `在双指针方法中，如果数组开成 long long 类型的，会导致超时`

code:

```c++
// 双指针的方法，效率：O(n)
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
typedef long long LL;

int arr[MAXN];

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int max_len = -1, pi = 0, pj = 0;
    while (pj < n)
    {
        while (pj < n && arr[pj] <= (LL) arr[pi] * p) pj++;
        if (max_len < (pj - pi)) max_len = pj - pi;
        pi++;
    }
    printf("%d", max_len);
    return 0;
}
```

```c++
// 二分查找的方法，效率：O(nlogn)
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

long long array[MAXN];

int main()
{
    long long n, p;
    scanf("%lld %lld", &n, &p);
    for (int i = 0; i < n; i++) scanf("%lld", &array[i]);
    sort(array, array + n);
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        // find the upper bound
        int front = i + 1, tail = n - 1, mid;
        while (front <= tail)
        {
            mid = (front + tail) / 2;
            if (array[mid] <= array[i] * p)
                front = mid + 1;
            else
                tail = mid - 1;
        }
        // end of finding upper bound
        if (front - i + 1 > max) max = front - i;

        /* 下面这两行代码等价于上述循环体内容，
        int j = upper_bound(array + i + 1, array + n, array[i] * p) - array;
        max = std::max(max, j);
        */
    }
    printf("%d", max);
    return 0;
}
```

# B1035

hint:

1. `测试点 2：存在陷阱，初始序列与中间序列相同时的情况`

2. `未解决`

code:

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 105

int n, raw_arr[MAXN], mid_arr[MAXN], cpy_arr1[MAXN], cpy_arr2[MAXN];

void input_arr(int arr[])
{
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void output_arr(int arr[])
{
    for (int i = 0; i < n; i++)
        printf(i == n - 1 ? "%d\n" : "%d ", arr[i]);
}

bool is_same(int a[], int b[])
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool sim_insertion_sort()
{
    bool is_ok = false;
    for (int i = 0; i < n; i++)
    {
        // 一趟插入
        int tmp = cpy_arr1[i], j;
        for (j = i - 1; j >= 0; j--)
            if (cpy_arr1[j] > tmp)
                cpy_arr1[j + 1] = cpy_arr1[j];
            else
                break;
        cpy_arr1[j + 1] = tmp;

        // 比较
        if (is_ok && !is_same(raw_arr, cpy_arr1))
        {
            printf("Insertion Sort\n");
            output_arr(cpy_arr1);
            break;
        }
        else
            is_ok = is_same(cpy_arr1, mid_arr);
    }
    return is_ok;
}

bool sim_merge_sort()
{
    bool is_ok = false;
    for (int step = 2; step / 2 < n; step += 2)
    {
        // 一趟归并
        for (int i = 0; i < n; i += step)
            std::sort(cpy_arr2 + i, cpy_arr2 + std::min(i + step, n));
        
        // 比较
        if (is_ok && !is_same(raw_arr, cpy_arr2))
        {
            printf("Merge Sort\n");
            output_arr(cpy_arr2);
            break;
        }
        else
            is_ok = is_same(cpy_arr2, mid_arr);
    }
    return is_ok;
}

int main()
{
    // input
    scanf("%d", &n);
    input_arr(raw_arr);
    input_arr(mid_arr);
    memcpy(cpy_arr1, raw_arr, sizeof(int) * n);
    memcpy(cpy_arr2, raw_arr, sizeof(int) * n);

    // simulate
    if (sim_insertion_sort()) ;
    else if (sim_merge_sort()) ;
    return 0;
}
```

# B1040 有几个PAT

hint:

`测试点3，4：考察数据较大，需要正确利用取余条件`

code:

```c++
#include <iostream>
#include <cstring>
#define MAX_LEN 100005
using namespace std;

char str[MAX_LEN];
int acc_p[MAX_LEN] = {}, len;

int main()
{
    // input
    scanf("%s", str);

    // init
    len = strlen(str);
    acc_p[0] = (str[0] == 'P');
    for (int i = 1; i < len; i++)
        acc_p[i] = acc_p[i - 1] + (str[i] == 'P' ? 1 : 0);
    
    // simulate reversely
    int acc_t = 0, ans = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == 'A')
            ans = (ans + acc_p[i - 1] * acc_t) % 1000000007;
        acc_t += (str[i] == 'T');
    }

    // output
    printf("%d", ans);
    return 0;
}
```

# B1045 快速排序

hint:

`测试点 2：考察当没有一个数字满足情况时的处理：应当输出一个换行`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int arr[MAXN], ans[MAXN], left_max[MAXN], right_min[MAXN] = {INT32_MAX};

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    left_max[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        left_max[i] = max(left_max[i - 1], arr[i]);
    }
    right_min[n + 1] = INT32_MAX;
    for (int i = n; i >= 1; i--)
    {
        right_min[i] = min(arr[i], right_min[i + 1]);
        if (left_max[i] <= arr[i] && arr[i] <= right_min[i])
            ans[cnt++] = arr[i];
    }
    printf("%d\n", cnt);
    for (int i = cnt - 1; i >= 0; i--)
        printf((i ? "%d " : "%d"), ans[i]);
    printf("\n");
    return 0;
}
```
