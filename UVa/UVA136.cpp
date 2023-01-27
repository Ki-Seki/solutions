#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int coeff[3] = {2, 3, 5};

int main()
{
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    pq.push(1); s.insert(1);
    for (int i = 1; ; i++)
    {
        LL x = pq.top(); pq.pop();
        if (i == 1500)
        {
            printf("The 1500'th ugly number is %d.\n", x);
            return 0;
        }
        for (int j = 0; j < 3; j++)
        {
            LL x2 = coeff[j] * x;
            if (!(s.count(x2)))
            {
                pq.push(x2);
                s.insert(x2);
            }
        }
    }
}



// #include <iostream>
// #include <set>

// using namespace std;

// set<int> primes;

// bool isPrime(long long n);

// bool isUgly(long long n);

// int main()
// {
//     long long n = 1, count = 0;
//     while (count < 1500)
//     {
// 		if (isPrime(n)) primes.insert(n);
//         count += (isUgly(n) ? 1 : 0);  // judge the ugly number
//         n++;  // loop var
//     } 
//     cout << n << endl;
//     return 0;
// }


// bool isPrime(long long n)
// {
//     for (long long i = 2; i <= n/2; i++)
//         if (n % i == 0) return false;
//     return true;
// }

// bool isUgly(long long n)  // 使用前确定 n 之前的数都已知其是否为素数
// {
// 	if (primes.count(n) && n >= 7) return false;
//     for (long long j = 7; j <= n/2; j++)  // 不能被大于等于 7 的素数整除
// 		if (n % j == 0 && primes.count(j)) return false;
//     return true;
// }