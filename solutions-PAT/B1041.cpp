#include <iostream>
#define MAXN 1005
typedef long long ll;
using namespace std;

struct {
    ll id;
    int examSeat;
} testSeat[MAXN]; // regard the index of it as number of the test seat

int main()
{
    ll id;
    int n, m, test, exam;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %d %d", &id, &test, &exam);
        testSeat[test].id = id;
        testSeat[test].examSeat = exam;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &test);
        printf("%lld %d\n", testSeat[test].id, testSeat[test].examSeat);
    }
    return 0;
}