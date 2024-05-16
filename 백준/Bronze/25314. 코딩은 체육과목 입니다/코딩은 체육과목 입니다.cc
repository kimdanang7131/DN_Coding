#include <iostream>

using namespace std;

int n;

int main()
{			
	cin >> n;
	
	int repeatNum = n / 4;
	
	string ans;
	
	while(repeatNum--)
	{
		ans += "long ";
	}
	ans += "int";
	
	cout << ans << endl;
	return 0;
}