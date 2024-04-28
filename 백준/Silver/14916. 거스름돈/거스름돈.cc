#include <iostream>

using namespace std;


int main()
{	
	int n , cnt =0;
	cin >> n;
	if(n % 5 ==0)
		cout << n / 5;
	else
	{
		while(n > 0)
		{
			n -= 2;
			cnt++;
			
			if(n % 5 == 0)
			{
				cout << cnt + n / 5;
				break;
			}
		}
	}
	
	if(n < 0)
		cout << -1;
	
	return 0;
}