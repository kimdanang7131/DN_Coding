#include <iostream>

using namespace std;

int t;
int a,b;

int main()
{			
	cin >> t;
	
	while(t--)
	{
		cin >> a >> b;
		printf("%d\n",a + b);
	}
	return 0;
}