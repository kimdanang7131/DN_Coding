#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int n;

bool CheckPrime(const int& num)
{
	if(num == 1)
		return false;
	if(num == 2)
		return true;	
	
	if(num % 2 == 0)
		return false;
		
	for(int i = 3; i <= sqrt(num); i++)
	{
		if(num % i == 0)
			return false;
	}
	
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	int cnt = 0;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		
		if(CheckPrime(tmp))
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}