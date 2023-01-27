#include <iostream>

using namespace std;

int main()
{
	int x, f1, f2;
	cin >> x;
	f1 = (x%2==0);
	f2 = (x>4 && x<=12);
	cout << (f1 && f2) << ' ' 
		<< (f1 || f2) << ' '
		<< (f1 ^ f2) << ' '
		<< (!f1 && !f2);
	return 0;
}

