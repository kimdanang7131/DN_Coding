#include <iostream>
using namespace std;

int a[31] = {0,};


int main()
{	
	for(int i=1; i<=28; i++)
	{
		int temp;
		cin >> temp;
		a[temp] = 1;
	}
	
	for(int i = 1; i <= 30; i++)
	{
		if(a[i] == 0)
		{
			cout << i << endl;
		}
	}

	return 0;
}