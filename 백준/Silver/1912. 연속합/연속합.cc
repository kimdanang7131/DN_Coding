#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[100001];
int d[100001];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	d[0] = a[0];
	int ans = d[0];
	for(int i= 1; i<n; i++)
	{
		d[i] = max(a[i], d[i-1] + a[i]);
		ans = max(ans, d[i]);
	}
	
	cout << ans;
}

