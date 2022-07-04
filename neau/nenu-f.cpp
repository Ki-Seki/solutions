#include <iostream>
using namespace std;

int n, coord[22][2];

int cal_dis(int x1, int y1, int x2, int y2)
{
    return (abs(x1-x2) + abs(y1-y2));
}

int main()
{
    cin >> n;
    while (n--)
    {
        // initialize
        int minx = 100, miny = 100, maxx = 0, maxy = 0;
        int m;

        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> coord[i][0] >> coord[i][1];
            if (coord[i][0] < minx) minx = coord[i][0];
            if (coord[i][1] < miny) miny = coord[i][1];
            if (coord[i][0] > maxx) maxx = coord[i][0];
            if (coord[i][1] > maxy) maxy = coord[i][1];
            // minx=1;miny=1;maxx=99;maxy=99;
        }

        // 找到最小距离
        long long min_d = 0x3fffffff, tmp;
        for (int x = minx; x <= maxx; x++)
            for (int y = miny; y <= maxy; y++)
            {
                tmp = 0;
                for (int i = 1; i <= m; i++)
                    tmp += cal_dis(x, y, coord[i][0], coord[i][1]);
                if (tmp < min_d) min_d = tmp;
            }
        printf("%d\n", min_d);
    }
    return 0;
}