#include<cstdio>

int main()
{
    int n, grade, passed = 0, great = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &grade);
        if (grade >= 85) great++;
        if (grade >= 60) passed++;
    }
    printf("%.0lf%\n%.0lf%\n", 100.0 * passed / n, 100.0 * great / n);
}
