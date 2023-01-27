/*
 * hint:
 * 1. 循环比较 0 < 1 < 2 < 3 < 0，利用 (i + 1) % len == j 确定 i < j
 * 2. 用 scanf 来接收 char 类型时，'\n' 也会收到；需要 getchar() 进行清除
*/ 

#include <iostream>

using namespace std;

int convert(char c)
{
    switch (c)
    {
    case 'B': return 0;
    case 'C': return 1;
    case 'J': return 2;
    }
    return 'N';
}

int convert(int n)
{
    switch (n)
    {
    case 0: return 'B';
    case 1: return 'C';
    case 2: return 'J';
    }
    return -1;
}

int main()
{
    int n, a, b, as, af, ap, bs, bf, bp, a_win[3] = {0}, b_win[3] = {0};
    char ca, cb;
    as = af = ap = bs = bf = bp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c %c", &ca, &cb);
        a = convert(ca);
        b = convert(cb);
        if ((a + 1) % 3 == b)  // 甲胜
        {
            as++;
            bf++;
            a_win[a]++;
        }
        else if (a == b)  // 平
        {
            ap++;
            bp++;
        }
        else  // 甲负
        {
            af++;
            bs++;
            b_win[b]++;
        }
    }
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a_win[i] > a_win[id1]) id1 = i;
        if (b_win[i] > b_win[id2]) id2 = i;
    }
    
    printf("%d %d %d\n%d %d %d\n%c %c", as, ap, af, bs, bp, bf, convert(id1), convert(id2));
    return 0;
}
