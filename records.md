# B1036 跟奥巴马一起编程

hint:

1. `四舍五入：Round(double x) = int(x + 0.5)`

2. `向上取整：Rounded_up(double x) = int(x) + 1 - int(1.0*int(x+1)-x)`

3. `向上取整的整除：Rounded_up(int a, int b) = (a - 1) / b + 1;`

code:

```c++
#include <iostream>
using namespace std;
int main()
{
    int n, rows;
    char c;
    cin >> n >> c;
    rows = n/2.0+0.5;
    for (int i = 0; i < rows; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < n; j++) printf("%c", c);
            printf("\n");
        }
        else
        {
            printf("%c", c);
            for (int j = 0; j < n - 2; j++) printf(" ");
            printf("%c\n", c);
        }
    }
    return 0;
}
```

# B1022 D进制的A+B

hint:

`不大于10进制的转换问题，可以利用以 10 为底的整型变量来模拟一个数组`

code:

```c++
#include <iostream>
using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    int sum = a + b;
    int ans[32], cnt=0;
    do {
        ans[cnt++] = sum % d;
        sum /= d;
    } while (sum > 0);
    for (int i = cnt - 1; i >= 0; i--) cout << ans[i];
    return 0;
}
```

# B1037 在霍格沃茨找零钱

hint:

`区间变换：`$x\in[a, b]\rArr y\in[c,d],\quad y=x\cdot\frac{d-c}{b-a}+\frac{cb-ad}{b-a}$

code:

```c++
#include <iostream>
#define S2G 17
#define K2S 29
using namespace std;

int main()
{
    int g1, s1, k1, g2, s2, k2, sign, g, s, k;
    unsigned long long sum1, sum2, diff;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    sum1 = g1 * S2G * K2S + s1 * K2S + k1;
    sum2 = g2 * S2G * K2S + s2 * K2S + k2;
    sign = (sum1 < sum2) * 2 - 1;  // 区间变换
    diff = sign * (sum2 - sum1);
    g = diff / K2S / S2G;
    s = diff / K2S % S2G;
    k = diff % K2S;
    cout << sign * g << '.' << s << '.' << k;
    return 0;
}
```

# B1002 写出这个数

hint:

1. `整数数位：Digit(int x) = Rounded_up(log10(x)，` $Digit(x) = \lceil \lg x \rceil$

2. `向上取整：Rounded_up(double x) = int(x) + 1 - int(1.0*int(x+1)-x)，` $Ru(x) = \lfloor x \rfloor + 1 - \lfloor 1.0 \cdot \lfloor x + 1 \rfloor - x \rfloor$

3. `向下取整：Rounded_down(double x) = int(x)` $Rd(x) = \lfloor x \rfloor$

4. `上下取整的关系：` $\lceil x \rceil = \lfloor x \rfloor + \Delta,\quad \Delta = 1 - \lfloor 1.0 \cdot \lfloor x + 1 \rfloor - x \rfloor$

code:

```c++
#include <iostream>
#include <cstring>
#define MAXN 105
using namespace std;

int main()
{
    char number[MAXN], trans[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    scanf("%s", number);
    int len = strlen(number), sum = 0;
    for (int i = 0; i < len; i++)
        sum += number[i] - '0';
    
    // due to the sum < 1000, there is no need to calculate the digit of var. sum
    if (0 <= sum && sum <= 9) printf("%s", trans[sum]);
    if (10 <= sum && sum <= 99) printf("%s %s", trans[sum/10], trans[sum%10]);
    if (100 <= sum && sum <= 999) printf("%s %s %s", trans[sum/100], trans[sum/10%10], trans[sum%10]);
    return 0;
}
```

# B1009 说反话

hint:

`自增、自减运算符在循环语句中慎用！尽量单独一句使用 or 用逗号运算符放置结尾`

code:

```c++
#include <iostream>
#define MAXN 85
using namespace std;

int main()
{
    char words[MAXN][MAXN];
    int cnt = 0;
    while (scanf("%s", words[cnt]) != EOF)
        cnt++;
    while (cnt)
        printf(cnt-1 ? "%s " : "%s\n", words[cnt-1]), cnt--;
    return 0;
}
```

# B1014 福尔摩斯的约会

hint:

1. `不要吝啬大括号！不要吝啬大括号！不要吝啬大括号！`

2. `不要在语法上找捷径！这是算法题，不是语法题！`

3. `及时转变思路，重写代码！`

code:

```c++
#include <iostream>
#include <cstring>
#define MAXN 70
using namespace std;

int main()
{
    char s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN], weekday[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    scanf("%s\n%s\n%s\n%s", s1, s2, s3, s4);
    int pos, len = min(strlen(s1), strlen(s2));
    for (pos = 0; pos < len; pos++)
        if (s1[pos] == s2[pos] && 'A' <= s1[pos] && s1[pos] <= 'G')
        {
            printf("%s ", weekday[s1[pos]-'A']);
            break;
        }
    for (pos++; pos < len; pos++)
        if (s1[pos] == s2[pos])
        {
            if ('0' <= s1[pos] && s1[pos] <= '9')
            {
                printf("%02d:", s1[pos] - '0');
                break;
            }
            else if ('A' <= s1[pos] && s1[pos] <= 'N')
            {
                printf("%02d:", s1[pos] - 'A' + 10);
                break;
            }
        }
    len = min(strlen(s3), strlen(s4));
    for (pos = 0; pos < len; pos++)
        if (s3[pos] == s4[pos])
            if (('a' <= s3[pos] && s3[pos] <= 'z') || ('A' <= s3[pos] && s3[pos] <= 'Z'))
            {
                printf("%02d\n", pos);
                break;
            }

    return 0;
}
```

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

# A1082 Read Number in Chinese

hint:

`简化逻辑的充分条件是：在编写代码前充分思考`

code:

```c++
#include <iostream>
#include <cstring>
#define MAXN 15
using namespace std;

const char ch_num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"},
base[4][5] = {"", "Shi", "Bai", "Qian"};

int main()
{
    bool hasOutput = false, innerNumber = false;
    char tmp[MAXN];
    int num[MAXN] = {};
    cin.getline(tmp, MAXN);
    int len = strlen(tmp), i = 0;

    // special judge
    if (len == 1)
    {
        printf("%s", ch_num[tmp[0]-'0']);
        return 0;
    }
    else if (len == 2 && tmp[0] == '-')
    {
        printf("Fu %s", ch_num[tmp[1]-'0']);
        return 0;
    }

    // get rid of the sign
    if (tmp[0] == '-')
    {
        printf("Fu");
        hasOutput = true;
        i = 1;
    }

    // standardization
    for (; i < len; i++)
        num[len-i] = tmp[i] - '0';

    // output 1 highest digits
    if (num[9] != 0)
    {
        if (hasOutput)
        {
            printf(" %s Yi", ch_num[num[9]]);
            innerNumber = true;
        }
            
        else
        {
            printf("%s Yi", ch_num[num[9]]);
            hasOutput = true;
        }
    }

    // output 4 middle digits
    bool hasZero = false, hasOutputInThisSection = false;
    for (int i = 8; i >= 5; i--)
    {
        if (num[i] != 0)  // non-0 digit
        {
            // handle 0
            if (hasZero)
            {
                printf(" ling");
                hasZero = false;
            }

            // handle number
            if (hasOutput) printf(" ");
            printf("%s", ch_num[num[i]]);

            // handle base
            if ((i-1) % 4 != 0) printf(" %s", base[(i-1)%4]);

            // handle status
            hasOutput = true;
            hasOutputInThisSection = true;
            innerNumber = true;
        }
        else  // 0 digit
        {
            if (innerNumber) hasZero = true;
        }
    }
    if (hasOutputInThisSection) printf(" Wan");
    if (hasOutput && !hasOutputInThisSection) printf(" ling");

    // output 4 low digits
    hasZero = false;
    for (int i = 4; i >= 1; i--)
    {
        if (num[i] != 0)  // non-0 digit
        {
            // handle 0
            if (hasZero)
            {
                printf(" ling");
                hasZero = false;
            }

            // handle number
            if (hasOutput) printf(" ");
            printf("%s", ch_num[num[i]]);

            // handle base
            if ((i-1) % 4 != 0) printf(" %s", base[(i-1)%4]);

            // handle status
            hasOutput = true;
        }
        else  // 0 digit
        {
            if (innerNumber) hasZero = true;
        }
    }
    return 0;
}
```

# B1015 德才论

hint:

`掌握重载为 sort() 提供支持的 cmp() 函数：其顺序是需要大在前，就返回大；需要小在前，就返回小于`

```c++
bool cmp(Student a, Student b)
{
    if (a.flag != b.flag) return a.flag < b.flag;  // 希望 flag 小的在前，就返回小于
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}
```

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

struct Student{
    int id, virtue, talent, sum, flag;
} stu[MAXN];

bool cmp(Student a, Student b)
{
    if (a.flag != b.flag) return a.flag < b.flag;
    else if (a.sum != b.sum) return a.sum > b.sum;
    else if (a.virtue != b.virtue) return a.virtue > b.virtue;
    else return a.id < b.id;
}

int main()
{
    // input and init
    int n, m = 0, l, h;
    scanf("%d%d%d", &n, &l, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &stu[i].id, &stu[i].virtue, &stu[i].talent);
        stu[i].sum = stu[i].virtue + stu[i].talent;
        if (stu[i].virtue < l || stu[i].talent < l) stu[i].flag = 5;
        else if (stu[i].virtue >= h && stu[i].talent >= h) stu[i].flag = 1;
        else if (stu[i].virtue >= h && stu[i].talent < h) stu[i].flag = 2;
        else if (stu[i].virtue < h && stu[i].talent < h && stu[i].virtue >= stu[i].talent) stu[i].flag = 3;
        else stu[i].flag = 4;
        if (stu[i].flag != 5) m++;
    }

    // sort
    sort(stu, stu + n, cmp);

    // output
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
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


# B1005 继续(3n+1)猜想

hint:

`测试点3，4：存在计算数字过程中超过 100 的数字，如果定义的 hash_table 容量较小，需要避免溢出`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAX_N 105
#define MAX_K 105
using namespace std;

bool isCovered[MAX_N] = {};
int arr[MAX_K] = {};

int main()
{
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &arr[i]);
        n = arr[i];
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3 * n + 1) / 2;
            if (n < MAX_N)  // avoid overflow
                isCovered[n] = true;
        }
    }
    sort(arr, arr + k);
    bool isFirstOutput = true;
    for (int i = k - 1; i >= 0; i--)
        if (! isCovered[arr[i]])
        {
            if (isFirstOutput)
            {
                printf("%d", arr[i]);
                isFirstOutput = false;
            }
            else printf(" %d", arr[i]);
        }
    return 0;
}
```

# B1020 月饼

hint:

`测试点2：若库存量和总价格不用 double 来定义，则会报错`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 1005

struct Mooncake{
    double storage, value, price;
} mc[MAXN];

bool cmp(Mooncake a, Mooncake b)
{
    return a.price > b.price;
}

int main()
{
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%lf", &mc[i].storage);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &mc[i].value);
        mc[i].price = 1.0 * mc[i].value / mc[i].storage;
    }
    std::sort(mc, mc + n, cmp);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (mc[i].storage <= d)
        {
            d -= mc[i].storage;
            profit += mc[i].value;
        }
        else
        {
            profit += d * mc[i].price;
            break;
        }
    }
    printf("%.2f", profit);
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
