#include <iostream>

using namespace std;

int main() 
{
	int a, b;
	cin >> a >> b;
	
	
	int cnt = 0;
	
	while(b != a)
	{
		int remain = b % 10;
		
		if(remain == 1)
		{
			b -= 1;
			b /= 10;
			++cnt;
			
			continue;
		}
		
		if(remain % 2 == 0)
		{
			b /= 2;
			++cnt;
		}
		else
		{
			cout << "-1"; 
			return 0;
		}
		
		if( b < a )
		{
			cout << "-1";
			return 0;
		}
	}
	
	cout << cnt + 1;
	
	return 0;
}