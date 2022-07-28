// 纯暴力不可取，超时了
#include <iostream>
#define MOD int(1e9+7)
#define MAXN 100000
using namespace std;
int n, sticks[MAXN], f[4], ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> sticks[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                for (int l = k + 1; l < n; l++)
                {
                    f[0] = sticks[i];
                    f[1] = sticks[j];
                    f[2] = sticks[k];
                    f[3] = sticks[l];
                    if ((f[0] == f[1] && f[1] == f[2] + f[3]) ||
                        (f[0] == f[2] && f[2] == f[1] + f[3]) ||
                        (f[0] == f[3] && f[3] == f[1] + f[2]) ||
                        (f[1] == f[2] && f[2] == f[0] + f[3]) ||
                        (f[1] == f[3] && f[3] == f[0] + f[2]) ||
                        (f[2] == f[3] && f[3] == f[0] + f[1]))
                        ans = (ans + 1) % MOD;

                    // for (int p = 0; p < 4; p++)
                    //     for (int q = p + 1; q < 4; q++)
                    //     {
                    //         if      (p==0 && q==1) {x=2; y=3;}
                    //         else if (p==0 && q==2) {x=1; y=3;}
                    //         else if (p==0 && q==3) {x=1; y=2;}
                    //         else if (p==1 && q==2) {x=0; y=3;}
                    //         else if (p==1 && q==3) {x=0; y=2;}
                    //         else if (p==2 && q==3) {x=0; y=1;}

                    //         if (four[p] == four[q] && )
                    //     }
                }
    cout << ans << endl;
    return 0;
}