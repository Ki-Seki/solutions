#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int level = ceil(log2(n+1)), max_level, max=-MAXN;
	for (int i = 0; i < level; i++)
	{
		int cnt = pow(2, i), sum = 0, tmp;
		for (int j = 0; j < cnt; j++)
			if (scanf("%d", &tmp)==1)
				sum += tmp;
			else
				break;
		if (sum > max)
		{
			max = sum;
			max_level = i + 1;
		}
	}
	printf("%d\n", max_level);
	return 0;
}
