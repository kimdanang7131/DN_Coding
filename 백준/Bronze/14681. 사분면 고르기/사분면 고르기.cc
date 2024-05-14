#include <iostream>

using namespace std;

int a,b;

int main()
{	
	cin >> a >> b;
	
	int quad = 0;
	
	if(a > 0)
	{
		quad = b > 0 ? 1 : 4;
	}
	else if(a < 0)
	{
		quad = b > 0 ? 2 : 3;
	}
	
	cout << quad << endl;
	
	return 0;
}