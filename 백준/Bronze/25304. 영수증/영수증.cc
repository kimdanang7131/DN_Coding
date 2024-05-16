#include <iostream>

using namespace std;

int x;
int n;

int main()
{			
	cin >> x;
	cin >> n;
	
	int ret = 0;
	while(n--)
	{
		int a,b;
		
		cin >> a >> b;
		ret +=  a * b;
	}
	
	string ans;
	ans = ( x == ret ) ? "Yes" : "No";
	
	cout << ans << endl;
	return 0;
}