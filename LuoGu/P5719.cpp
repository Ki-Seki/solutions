#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    double ave1=0, ave2=0, count1=0, count2=0;
    cin >> n >> k;
    for(int i=1 ;i<n+1; i++)
    {
        if(i%k == 0)
        {
            ave1 += i;
            count1++;
        }
        else
        {
            ave2 += i;
            count2++;
        }
    }
    printf("%.1f %.1f", ave1/count1, ave2/count2);
    return 0;
}
