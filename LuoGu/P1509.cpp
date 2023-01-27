#include <iostream>
#include <cmath>

using namespace std;

int cost(int n, int amount, int price);

int main()
{
	int n, t1, t2, min;
	cin >> n >> t1 >> t2;
	min = cost(n, t1, t2);
	cin >> t1 >> t2;
	if (cost(n, t1, t2)<min)
		min = cost(n, t1, t2);
	cin >> t1 >> t2;
	if (cost(n, t1, t2)<min)
		min = cost(n, t1, t2);
	cout << min;
	return 0;
}

int cost(int n, int amount, int price)
{
	return int(ceil(n/double(amount))) * price;
}

