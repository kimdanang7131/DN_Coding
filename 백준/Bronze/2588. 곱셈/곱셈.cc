#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int num1, num2;
	int sum = 0;
	int count = 0;
	cin >> num1 >> num2;

	while (num2 > 0)
	{
		cout << num1 * (num2 % 10) << endl;
		sum += (num1 * (num2 % 10)) * (int)(pow(10,count++));
		num2 /= 10;

	}

	cout << sum << endl;

	return 0;
}