#include <iostream>
#include <vector>

using namespace std;

int n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	int base = n;
	
	int minNum = base;
	
	while(n > 0)
	{
		n--;
		
		int temp  = n;
		int sum = 0;
		
		while(temp > 0)
		{
		
			sum  += temp % 10;
			temp /= 10;
		
		}
		
		if(sum + n == base)
		{
			minNum = min(minNum,n);
		}
	}
	
	if(minNum == base)
	    cout << 0 << endl;
	else
		cout << minNum << endl;

	return 0;
}