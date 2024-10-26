#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

long long p[101];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	
	p[0] = 0;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		for(int i = 4; i <= n; i++)
		{
			p[i] = p[i-3] + p[i-2];
		}
		
		cout << p[n] << '\n';
	}
	return 0;

}
