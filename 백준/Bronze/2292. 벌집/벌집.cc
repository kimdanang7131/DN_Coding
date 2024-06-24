#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	
	int   i = 1;
	int ans = 1;
	int cnt = 1;
	
	while(cnt < n)
	{
		cnt += 6 * i++;
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}