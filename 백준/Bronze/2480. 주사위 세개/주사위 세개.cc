#include <iostream>

using namespace std;

int a,b,c;

int main()
{	
	cin >> a >> b >> c;
	
	int ret = 0;
	
	if(a == b && b == c && c == a)
	{
		ret = 10000 + (a * 1000);	
	}
	else if(a == b || b == c || a== c)
	{
		int sameNum = 0;
		if(a == b)
		{
			sameNum = a;
		}
		else if(b == c)
		{
			sameNum = b;
		}
		else if(c == a)
		{
			sameNum = c;
		}
		
		ret = 1000 + (sameNum * 100);
	}
	else
	{
		int maxNum = 0;
		
		maxNum = max(a,max(b,c));
		
		ret = maxNum* 100;
	}
	
	cout << ret << endl;

	return 0;
}