#include <iostream>

using namespace std;

long long answer;

int main() 
{
	long long n;
	cin >> n;
	
		
	long long ret = 0;
	for(long long i = 1; i <= 4294967295; i++)
	{
		ret = (i + 1) * i / 2;
		answer = i - 1;
		
		if(ret > n)
			break;
	}
	
	cout << answer << endl;
	
	return 0;
}