#include <iostream>
using namespace std;

int n;
int a[101];
int ans;

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 0 ;i < n; i++)
	{
		cin >> a[i];
	}
	
	int fNum;
	cin >> fNum;
	for(int i=0; i<n; i++)
	{
		if(a[i] == fNum)
			++ans;
	}
	
	cout << ans << endl;

	return 0;
}