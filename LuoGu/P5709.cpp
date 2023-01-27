#include <iostream>

using namespace std;

int main()
{
	int m, t, s;
	cin >> m >> t >> s;
	if (t==0)
		cout << 0;
	else
		if (s%t==0)
			if (m - s/t >0)
				cout << m-s/t;
			else
				cout << 0;
		else
			if (m - s/t -1 > 0)
				cout << m-s/t-1;
			else
				cout << 0;
	return 0;
}

