/*
 * hint:
 * 不大于10进制的转换问题，可以利用以 10 为底的整型变量来模拟一个数组
*/
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