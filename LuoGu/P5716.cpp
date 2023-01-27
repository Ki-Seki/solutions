#include <iostream>

using namespace std;

bool isLeapYear(int y);

int main()
{
	int y, m;
	cin >> y >> m;
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: cout << 31; break;
		case 2:
		{
			if (isLeapYear(y))
				cout << 29;
			else
				cout << 28;
			break;
		}
		default: cout << 30;
	}
	return 0;
}

bool isLeapYear(int y)
{
	if (y%400==0)
		return true;
	else if (y%100==0)
		return false;
	else if (y%4==0)
		return true;
	else
		return false;
}
