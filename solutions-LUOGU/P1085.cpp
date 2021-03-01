#include <iostream>

using namespace std;

int main()
{
	int t1, t2, len=0, index=0;
	for(int i=0;i<7;i++)
	{
		cin >> t1 >> t2;
		if (t1+t2>len)
		{
			len = t1 + t2;
			index = i + 1;
		}
	}
	if (len > 8)
		cout << index;
	else
		cout << 0;
	return 0;
}

