#include <iostream>

using namespace std;

float getBMI(float weight, float height);

int main()
{
	float m, h, bmi;
	cin >> m >> h;
	bmi = getBMI(m, h);
	if (bmi<18.5)
	{
		cout << "Underweight";
	}
	else if (bmi>=18.5 && bmi<24)
	{
		cout << "Normal";
	}
	else
	{
		cout << bmi << endl << "Overweight";
	}
	
	return 0;
}

float getBMI(float weight, float height)
{
	float bmi;
	bmi = weight / (height * height);
	return bmi;
}