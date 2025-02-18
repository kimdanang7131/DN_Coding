#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    vector<int> v(n + 1);
	vector<int> dp(n + 1);
	
	for(int i=1; i<=n; i++)
	{
		cin >> v[i];
	}
	
	dp[1] = v[1];
	if(n >= 2)
	{
		dp[2] = v[1] + v[2];
	}
	
	
	for(int i = 3; i <= n; i++)
	{
		dp[i] = max({dp[i-1] , dp[i-2]+v[i], dp[i-3] +v[i-1]+v[i]});
	}

	cout << dp[n] << endl;
	    
    return 0;
}