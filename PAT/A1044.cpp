#include <iostream>
#define MAX_N 100005
#define MAX_M 100000005
using namespace std;

int acc_chain[MAX_N] = {}, ans[MAX_N][2];

// return the rightmost end of the diamond able to pay
int binarySearch(int left, int right, int price)
{
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (acc_chain[mid] >= price)
            right = mid;
        else
            left = mid + 1;
    }
    if (acc_chain[right] >= price)
        return right;
    else
        return -1;
}

int main()
{
    // input
    int n, m, tmp;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        acc_chain[i] = acc_chain[i-1] + tmp;
    }

    // binary search
    int len = 0, minPayment = MAX_M;
    for (int leftEnd = 1; leftEnd <= n; leftEnd++)
    {
        int rightEnd = binarySearch(leftEnd, n, m + acc_chain[leftEnd-1]),
        payment = acc_chain[rightEnd] - acc_chain[leftEnd-1];
        if (rightEnd != -1 && payment <= minPayment)
        {
            ans[len][0] = leftEnd;
            ans[len][1] = rightEnd;
            minPayment = payment;
            len++;
        }
    }

    // output
    for (int i = 0; i < len; i++)
    {
        int payment = acc_chain[ans[i][1]] - acc_chain[ans[i][0] - 1];
        if (payment == minPayment)
            printf("%d-%d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}