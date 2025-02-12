#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff


int n, k;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    vector<int> w(n+1), v(n+1);
    
    for(int i=1; i<=n; i++)
    {
    	cin >> w[i] >> v[i];
	}
	
	vector<vector<int>> dp(n+1, vector<int>(k+1,0));
	
	for(int i = 1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(j >= w[i])
			{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
    cout << dp[n][k] << endl;
	
    return 0;
}