# A1036 Boys vs Girls

hint:

`C风格字符串不可比较`

code:

```c++
#include <iostream>
using namespace std;

struct {
    char name[15], id[15];
    int grade;
} f={"", "", -1}, m={"", "", 101}, tmp;

int main()
{
    int n, diff;
    char sex;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %c %s %d", tmp.name, &sex, tmp.id, &tmp.grade);
        if (sex == 'M' && tmp.grade <= m.grade) m = tmp;
        if (sex == 'F' && tmp.grade >= f.grade) f = tmp;
    }
    if (f.grade != -1) printf("%s %s\n", f.name, f.id); else printf("Absent\n");
    if (m.grade != 101) printf("%s %s\n", m.name, m.id); else printf("Absent\n");
    if(f.grade != -1 && m.grade != 101) printf("%d\n", f.grade-m.grade); else printf("NA\n");
    return 0;
}
```

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

# A1031 Hello World for U

hint:

1. `逗号运算符自左向右结合，考虑变量定义的序列`

2. `strlen(str) 方法在 <string.h> 定义`

code:

```c++
#include <iostream>
#include <cstring>
#define MAX 85
using namespace std;

char str[MAX], graph[MAX/2][MAX/2];

int main()
{
    // init
    scanf("%s", str);
    int N=strlen(str), n1=(N+2)/3, n2=N+2-2*n1;
    for (int i = 0; i < MAX / 2; i++)
        for (int j = 0; j < MAX / 2; j++)
            graph[i][j] = ' ';
    
    // convert
    int pos = 0;
    for (int i = 1; i <= n1; i++) graph[i][1] = str[pos++];  // first stroke
    for (int i = 2; i <= n2; i++) graph[n1][i] = str[pos++];  // second stroke
    for (int i = n1 - 1; i >= 1; i--) graph[i][n2] = str[pos++];  // third stroke

    // output
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++) printf("%c", graph[i][j]);
        printf(i == n1 ? "" : "\n");
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

# A1077 Kuchiguse

hint:

1. `<algorithm>：reverse()`

2. `PAT 不再支持 <cstdio>：gets()，可以用cin.getline() 来替代。此两个函数都是遇到 '\n'停止读取`

code:

```c++
#include <iostream>
#include <cstring>
// #include <cstdio>
#include <algorithm>
#define MAXN 1005
#define MAXSIZE 260
using namespace std;

char words[MAXN][MAXSIZE];

int main()
{
    int n, minLen = MAXSIZE;
    cin >> n;
    getchar();  // get rid of the '\n'
    for (int i = 0; i < n; i++)
    {
        // gets(words[i]);  // PAT not supports gets()
        cin.getline(words[i], MAXSIZE);
        int len = strlen(words[i]);
        if (len <= minLen) minLen = len;
        reverse(words[i], words[i] + len);
    }
    int cnt = 0;
    for (int i = 0; i < minLen; i++)
    {
        bool consistent = true;
        char ch = words[0][i];
        for (int j = 1; j < n; j++)
        {
            if (ch != words[j][i])
            {
                consistent = false;
                break;
            }
        }
        if (consistent) cnt++;
        else break;
    }

    if (cnt)
    {
        for (int i = cnt - 1; i >= 0; i--)
            printf("%c", words[0][i]);
        printf("\n");
    }
    else 
        printf("nai\n");
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

# A1055 The World's Richest

hint:

`测试点3：含有年龄为 200 的数据，注意定义数组的边界大小`

code:

```c++
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100005
#define MAXAGE 205
using namespace std;

struct Person{
    char name[10];
    int age, worth;
} rcd[MAXN], new_rcd[MAXN];

int age[MAXAGE] = {};  // denote the count of people with age of index

bool cmp(Person a, Person b)
{
    if (a.worth != b.worth) return a.worth > b. worth;
    else if (a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%s %d %d", rcd[i].name, &rcd[i].age, &rcd[i].worth);
    
    // sort
    sort(rcd, rcd + n, cmp);

    // preprocess: delete redundant data
    int new_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (age[rcd[i].age] <= 100)
        {
            age[rcd[i].age]++;
            new_rcd[new_n++] = rcd[i];
        }
    }

    // output
    for (int kase = 1; kase <= k; kase++)
    {
        printf("Case #%d:\n", kase);
        bool hasOutput = false;
        int m, l, r;
        scanf("%d %d %d", &m, &l, &r);
        for (int i = 0; i < new_n && m > 0; i++)
        {
            if (l <= new_rcd[i].age && new_rcd[i].age <= r)
            {
                hasOutput = true;
                m--;
                printf("%s %d %d\n", new_rcd[i].name, new_rcd[i].age, new_rcd[i].worth);
            }
        }
        if (!hasOutput) printf("None\n");
    }
    return 0;
}
```

# A1075 PAT Judge

hint:

`测试点0，测试点4：考察对“满分数量”的计算`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 10005
#define MAXK 10
#define MAXM 100005
using namespace std;

struct Student{
    int id, score[MAXK], total, full_marks_count;
    bool toShow;

    Student()
    {
        id = MAXN;
        for (int i = 0; i < MAXK; i++) score[i] = -1;
        total = 0;
        full_marks_count = 0;
        toShow =false;
    }
} stu[MAXN];

int prob[MAXK];  // denote the full marks of problems; start from i = 1

bool cmp(Student a, Student b)
{
    if (a.total != b.total) return a.total > b.total;
    else if (a.full_marks_count != b.full_marks_count) return a.full_marks_count > b.full_marks_count;
    else return a.id < b.id;
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
        scanf("%d", &prob[i]);
    int user_id, problem_id, obtained;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &user_id, &problem_id, &obtained);

        // get every item in the Student object, stu[user_id]
        stu[user_id].id = user_id;
        if (obtained >= stu[user_id].score[problem_id])  // coverage
        {
            if (obtained == -1)  // special judge
            {
                stu[user_id].score[problem_id] = 0;
                continue;
            }
            int before = stu[user_id].score[problem_id] == -1 ? 0 : stu[user_id].score[problem_id];
            stu[user_id].total += obtained - before;
            stu[user_id].score[problem_id] = obtained;
            if (obtained == prob[problem_id] && before < prob[problem_id]) stu[user_id].full_marks_count++;
            stu[user_id].toShow = true;
        }
    }
    sort(stu + 1, stu + n + 1, cmp);  // user_id start from 1 rather than 0
    int rank = 1;
    for (int i = 1; i <= n && stu[i].toShow; i++)
    {
        // ouptut rank
        if (i > 1 && stu[i].total != stu[i-1].total)
        {
            printf("%d", i);
            rank = i;
        }
        else printf("%d", rank);

        // output id and total marks
        printf(" %05d %d", stu[i].id, stu[i].total);

        // output single marks
        for (int j = 1; j <= k; j++)
        {
            if (stu[i].score[j] == -1) printf(" -");
            else printf(" %d", stu[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}
```

# A1080 Graduate Admission

hint:

`测试点1，测试点2：考察对排序后 stu[MAXN] 的 i（下标）和id（属性）的区别的认知程度`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 40005
#define MAXM 105
#define MAXK 10
using namespace std;

struct Student {
    int ge, gi, final, rank, id, preference[MAXK];
} stu[MAXN];

struct School {
    int quota, cnt_received, index_received[MAXN], index_last_received;
    School ()
    {
        cnt_received = 0;
        index_last_received = -1;
    }
} sch[MAXM];

bool cmp_student(Student a, Student b)
{
    if (a.final != b.final) return a.final > b.final;
    else return a.ge > b.ge;
}

bool cmp_id(int a, int b)
{
    return stu[a].id < stu[b].id;
}

int main()
{
    // input
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        scanf("%d", &sch[i].quota);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].final = stu[i].ge + stu[i].gi;
        stu[i].id = i;
        for (int j = 0; j < k; j++)
            scanf("%d", &stu[i].preference[j]);
    }

    // sort
    sort(stu, stu + n, cmp_student);

    // get ranks
    for (int i = 0; i < n; i++)
        if (i > 0 && stu[i].final == stu[i-1].final && stu[i].ge == stu[i-1].ge)
            stu[i].rank = stu[i-1].rank;
        else
            stu[i].rank = i + 1;
    
    // simulate admission
    for (int i = 0; i < n; i++)
    {
        // search proper school for stu[i]
        int choice = 0, id_target_school, rcv_window, index_last_received, rank_last_received;
        for (; choice < k; choice++)
        {
            id_target_school = stu[i].preference[choice];
            rcv_window = sch[id_target_school].quota - sch[id_target_school].cnt_received;
            index_last_received = sch[id_target_school].index_last_received;
            rank_last_received = stu[sch[id_target_school].index_last_received].rank;
            if (rcv_window > 0) break;
            else if (index_last_received != -1 && rank_last_received == stu[i].rank) break;
        }
        
        // test
        // printf("\nstu:%d -> sch:%d\n", i, id_target_school);

        // sch[id_target_scholl] admit stu[i]
        if (choice < k)
        {
            int cnt = sch[id_target_school].cnt_received++;
            sch[id_target_school].index_received[cnt] = i;
            sch[id_target_school].index_last_received = i;
        }
    }

    // output
    for (int i = 0; i < m; i++)
    {
        if (sch[i].index_last_received != -1)
        {
            sort(sch[i].index_received, sch[i].index_received + sch[i].cnt_received, cmp_id);
            for (int j = 0; j < sch[i].cnt_received; j++)
                printf(j == sch[i].cnt_received - 1 ? "%d" : "%d ", stu[sch[i].index_received[j]].id);
        }
        printf("\n");
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

# A1048 Find Coins

code:

```c++
/*
 * 本题尝试了四种方法，三种通过测试，一种不可用
 * 1. 哈希桶排序：利用桶排序读入数据，从小到大遍历数组
 * 2. 二分查找：读入数据并按普通方法排序，对数组每一个元素 a[i]，二分查找 m - a[i]
 * 3. 哈希桶排序 + 二分查找：不可用，因为哈希桶排序消去了二分查找时的种植可比性
 * 4. 双指针：排序后通过前后指针向中间靠近
*/

// // 哈希桶排序
// #include <iostream>
// #define MAX_M 1005
// using namespace std;

// int coins[MAX_M] = {};

// int main()
// {
//     int n, m, coin;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &coin);
//         coins[coin]++;
//     }
//     for (int i = 0; i < MAX_M / 2; i++)
//     {
//         if (coins[i] > 0)
//         {
//             coins[i]--;  // avoid error when i == m - i
//             if (coins[m - i] > 0)
//             {
//                 printf("%d %d", i, m - i);
//                 return 0;
//             }
//         }
//     }
//     printf("No Solution");
//     return 0;
// }

// // 二分查找
// #include <iostream>
// #include <algorithm>
// #define MAX_N 100005
// using namespace std;

// int coins[MAX_N] = {};

// int binarySearch(int low, int high, int x)
// {
//     int mid;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (coins[mid] == x)
//             return mid;
//         else if (coins[mid] < x)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }
//     return -1;
// }

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &coins[i]);
//     sort(coins, coins + n);
//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         ans = binarySearch(i + 1, n - 1, m - coins[i]);
//         if (ans != -1) break;
//     }
//     if (ans != -1)
//         printf("%d %d", m - coins[ans], coins[ans]);
//     else
//         printf("No Solution");
//     return 0;
// }

// // 哈希桶排序 + 二分查找
// #include <iostream>
// #define MAX_FACE_VALUE 505
// using namespace std;

// int coins[MAX_FACE_VALUE] = {};

// int main()
// {
//     // input && init
//     int n, m, coin;
//     scanf("%d %d", &n, &m);
//     int low = 505, high = -1;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &coin);
//         coins[coin]++;
//         if (coin > high) high = coin;
//         if (coin < low) low = coin;
//     }

//     // binary search
//     // 实践证明，无法用桶排序 + 二分查找结合的方法。二分查找的关键就在于：中值可比性；而桶排序消除了中值可比性
//     while (low < high)
//     {
//         int mid = (low + high) /2;
//         if (m - mid <= 500 && m - mid != m)
//             if (coins[mid] && coins[m - mid])
//                 high = mid;
//             else
//     }

//     printf("No Solution");
//     return 0;
// }

// 双指针
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int a[MAXN], n, m;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (a[left] + a[right] == m) break;
        else if (a[left] + a[right] < m) left++;
        else right--;
    }
    if (left != right && a[left] + a[right] == m)
        printf("%d %d", a[left], a[right]);
    else
        printf("No Solution");
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


# A1037 Magic Coupon

hint:

`测试点1，5：考察当 coupon 中正数（负数）和 product 中正数（负数）个数相等时的处理`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 100005

using namespace std;

long long coupon[MAXN], product[MAXN];

bool cmp(long long a, long long b)
{
    return a > b;
}

int main()
{
    int nc, np;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++)
        scanf("%lld", &coupon[i]);
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
        scanf("%lld", &product[i]);
    long long ans = 0;
    int minlen = min(nc, np);
    sort(coupon, coupon + nc);
    sort(product, product + np);
    for (int i = 0; i < minlen; i++)
        if (coupon[i] < 0 && product[i] < 0)
            ans += coupon[i] * product[i];
        else break;
    sort(coupon, coupon + nc, cmp);
    sort(product, product + np, cmp);
    for (int i = 0; i < minlen; i++)
        if (coupon[i] > 0 && product[i] > 0)
            ans += coupon[i] * product[i];
        else break;
    printf("%d", ans);
    return 0;
}
```

# A1067 Sort with Swap(0, i)

hint:

1. `测试点1，2：当 0 已经回到原位，向下寻找没有归位的值的时候，要进行优化。具体就是记录当前最小的未归位的下标`

2. `测试点3：初始时，0 就已经在原位`

code:

```c++
#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int numbers[MAXN] = {};

int main()
{
    int n, tmp, cnt;
    scanf("%d", &n);
    cnt = n - 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        numbers[tmp] = i;
        if (tmp == i && tmp != 0) cnt--;
    }
    int ans = 0, i = 1;
    while (cnt > 0)
    {
        if (numbers[0] != 0)
        {
            swap(numbers[0], numbers[numbers[0]]);
            cnt--;
        }
        else
        {
            for (; i < n; i++)
                if (numbers[i] != i)
                {
                    swap(numbers[0], numbers[i]);
                    break;
                }
        }
        ans++;
    }
    printf("%d", ans);
    return 0;
}
```

# A1038 Recover the Smallest Number

hint:

`证明：对于已经拼接好的最小序列，对任意 0 ≤ i < j ≤ n - 1，有 number[i] + number[j] <= number[j] + number[i]（ + 表示数字拼接）。反证法证明如下：`

1. `假设结论反面成立：存在 0 ≤ i < j ≤ n - 1，使得number[i] + number[j] > number[j] + number[i]`
2. `易知，此时，只要 i 号和 j 号数字段交换位置就可以使序列更小，因此与前提冲突。`
3. `假设不成立，原结论正确。`

code:

```c++
#include <iostream>
#include <algorithm>
#include <string>
#define MAXN 10005
using namespace std;

string number[MAXN];

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n, cmp);
    bool time_to_output = false;
    for (int i = 0; i < n; i++)
    {
        int len = number[i].length();
        for (int j = 0; j < len; j++)
            if (time_to_output)
                cout << number[i][j];
            else if (! time_to_output && number[i][j] != '0')
            {
                time_to_output = true;
                cout << number[i][j];
            }
    }
    if (! time_to_output) cout << '0';
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

# A1029 Median

code:

```c++
/*
 * 本题使用两种方法，均通过评测：
 * 归并 + 直接排序
*/

// 用归并算法
#include <iostream>
#include <limits.h>
#define MAXN 1000005
using namespace std;

long arr1[MAXN], arr2[MAXN];

int main()
{
    // input
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        scanf("%ld", &arr1[i]);
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        scanf("%ld", &arr2[i]);
    
    // optimize
    arr1[n1] = arr2[n2] = LONG_MAX;
    
    // simulate merging
    int p1 = 0, p2 = 0, p_mid = (n1 + n2 - 1) / 2, p = 0;
    long tmp;
    while (p <= p_mid)
    {
        tmp = (arr1[p1] <= arr2[p2]) ? (arr1[p1++]) : (arr2[p2++]);
        p++;
    }
    printf("%ld", tmp);
    return 0;
}

// // 用系统自带的排序
// #include <iostream>
// #include <algorithm>
// #define MAXN 1000005
// using namespace std;

// long long arr[MAXN * 2];

// int main()
// {
//     int n1, n2;
//     scanf("%d", &n1);
//     for (int i = 0; i < n1; i++)
//         scanf("%lld", &arr[i]);
//     scanf("%d", &n2);
//     for (int i = n1; i < n1 + n2; i++)
//         scanf("%lld", &arr[i]);
//     sort(arr, arr + n1 + n2);
//     printf("%lld", arr[(n1 + n2 - 1) / 2]);
//     return 0;
// }
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

