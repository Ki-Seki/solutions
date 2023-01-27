#include <iostream>
#include <cstring>
#define MAXLEN 35
using namespace std;

int convert(int dst[], int src, int base);
bool isPalin(int dst[], int len);

int main()
{
    int n, b, len, dst[MAXLEN];
    cin >> n >> b;
    len = convert(dst, n, b);
    printf(isPalin(dst, len) ? "Yes\n" : "No\n");
    for (int i = len - 1; i >= 0; i--) printf((i == 0) ? "%d" : "%d ", dst[i]);
    return 0;
}

// dst's number should be output reversely, from (len - 1) to 0
// returnee is the length of dst
int convert(int dst[], int src, int base)
{
    int cnt = 0;
    do {
        dst[cnt++] = src % base;
        src /= base;
    } while (src > 0);
    return cnt;
}

bool isPalin(int dst[], int len)
{
    for (int i = 0; i <= len / 2; i++)
        if (dst[i] != dst[len-1-i])
            return false;
    return true;
}