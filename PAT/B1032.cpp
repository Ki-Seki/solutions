/*
 * hint:
 * 注意循环时自问：到底遍历的是什么？
*/
#include <iostream>
#define MAXN 100005
using namespace std;

int Score[MAXN] = {0};

int main()
{
    int n, no, s, max_no = 0, max_s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) // 遍历的是 n 个输入
    {
        scanf("%d%d", &no, &s);
        Score[no] += s;
    }
    for (int i = 0; i < MAXN; i++)  // 遍历的是 Score[] 数组
    {
        if (Score[i] >= max_s)
        {
            max_no = i;
            max_s = Score[i];
        }
    }
    printf("%d %d\n", max_no, max_s);
    return 0;
}