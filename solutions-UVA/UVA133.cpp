#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) == 3 && !(n == 0 && k == 0 && m==0))
    {
        int left = n;
        bool seq[n];
        memset(seq, true, sizeof(seq));
        int pointerA = -1, pointerB = n; // 维护A和B两个指针，指示当前A和B的位置
        while (left > 0)
        {
            int stepA = 0, stepB = 0; // 累积量
            while (stepA < k) // find the next k
            {
                if (seq[(pointerA+1) % n]) stepA++;
                pointerA = (pointerA+1) % n;
            }
            while (stepB < m) // find the next m
            {
                if (seq[(pointerB+n-1) % n]) stepB++;
                pointerB = (pointerB+n-1) % n;
            }

            // kick off the k & m
            if (pointerA == pointerB)
            {
                seq[pointerA] = false;
                left--;
                printf("%3d", pointerA+1);
            }
            else
            {
                seq[pointerA] = false;
                seq[pointerB] = false;
                left -= 2;
                printf("%3d%3d", pointerA+1, pointerB+1);
            }
            if (left > 0) printf(",");
        }
        printf("\n");
    }
    return 0;
}