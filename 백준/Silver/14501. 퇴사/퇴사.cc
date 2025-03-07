#include <iostream>
#include <vector>
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

	
	vector<int> T(n + 1);
	vector<int> P(n + 1);
	
	vector<int> dp(n + 2);
	
	for(int i =1; i <= n; i++)
	{
		cin >> T[i] >> P[i];
	}
	
	for(int i = n; i >= 1; i--)
	{
		if( T[i] + i - 1 > n)
		{
			dp[i] = dp[i+1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
		}	
	}
	
	cout << dp[1] << endl;

    return 0;
}