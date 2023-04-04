#include <iostream>
using namespace std;


int main()
{
	int y = 0;
	do
	{
		cin >> y;
	} while (y < 1000 || y > 3000);

	cout << y - 544 +1 << endl;
	return 0;
}