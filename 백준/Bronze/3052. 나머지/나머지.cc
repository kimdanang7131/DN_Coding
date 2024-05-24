#include <iostream>
using namespace std;

int rm[42];
int ans;

int main()
{	
	for(int i=0; i<10; i++)
	{
		int a;
		cin >> a;
		rm[a % 42] = 1;
	}
	
	
	for(int i=0; i<42; i++)
	{
		ans += rm[i];
	}

	cout << ans<< endl;
	return 0;
}