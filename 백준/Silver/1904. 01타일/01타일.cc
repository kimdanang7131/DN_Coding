#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
long long fibo[1000001];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	fibo[0] = 0, fibo[1] = 1, fibo[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		fibo[i] = (fibo[i-2] + fibo[i-1]) % 15746;
	}
	
	cout << fibo[n] << '\n';
	
	return 0;

}
