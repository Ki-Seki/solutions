/*
 * hint:
 * 本题使用了状态机 FSM 的思想求解
 * 时间复杂度 O(n) 空间复杂度 O(1)
 * 第一个代码为部分状态机 第二个代码使用完全状态机
 * 状态机图示见 B1003.png，图片源文件见：https://kdocs.cn/l/cobi7ul6fhWd
*/

// 使用部分状态机的思想：即不完全按照标准的理论来写，非生搬硬套，不易理解
#include <iostream>

int main()
{
    int n;
    scanf("%d\n", &n);  // 防止 getchar() 读入 \n
    for (int i = 0; i < n; i++)
    {
        bool ans = true;
        int status_code = 0,  // 有限状态机 FSM 的状态码
            l1 = 0, l2 = 0, l3 = 0;  // 分别表示 P左边 PT之间 T右边 的 A 的数量
        while (status_code != 6)
        {
            char tmp = getchar();
            switch (status_code)  // 根据状态码做出具体行为；为完全符合状态机，可以将 tmp = getchar(); 转移到每个 case 子句的首行
            {
            case 0:  // 初始状态
                if (tmp == 'A')
                {
                    status_code = 1;
                    l1++;
                }
                else if (tmp == 'P')
                    status_code = 2;
                else if (tmp == '\n')
                    status_code = 6;
                else
                    ans = false;
                break;
            case 1:  // 已接收到 P 左边的 A
                if (tmp == 'A')
                    l1++;
                else if (tmp == 'P')
                    status_code = 2;
                else if (tmp == '\n')
                {
                    status_code = 6;
                    ans = false;
                }
                else
                    ans = false;
                break;
            case 2:  // 已接收到 P
                if (tmp == 'A')
                {
                    status_code = 3;
                    l2++;
                }
                else if (tmp == '\n')
                {
                    status_code = 6;
                    ans = false;
                }
                else
                    ans = false;
                break;
            case 3:  // 已接收到 PT 间的 A
                if (tmp == 'A')
                    l2++;
                else if (tmp == 'T')
                    status_code = 4;
                else if (tmp == '\n')
                {
                    status_code = 6;
                    ans = false;
                }
                else
                    ans = false;
                break;
            case 4:  // 已接收到 T
                if (tmp == 'A')
                {
                    status_code = 5;
                    l3++;
                }
                else if (tmp == '\n')
                    status_code = 6;
                else
                    ans = false;
                break;
            case 5:  // 已接收到 T 右边的 A
                if (tmp == 'A')
                    l3++;
                else if (tmp == '\n')
                    status_code = 6;
                else
                    ans = false;
            }
        }
        if (l3 != l1 * l2 || l2 < 1) ans = false;
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}

// // 使用完全状态机的思想
// #include <iostream>

// int main()
// {
//     return 0;
// }