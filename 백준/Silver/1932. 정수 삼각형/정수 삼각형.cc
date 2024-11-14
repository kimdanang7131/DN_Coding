#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n;

	vector<vector<int>> v;
	v.assign(n  + 1 , vector<int>( n + 1));
		
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> v[i][j];
		}
	}

	
	vector<vector<int>> dp;
	dp.assign(n + 1 , vector<int>(n + 1));
	dp[1][1] = v[1][1];
	
	if(n == 1)
	{
		cout << v[1][1];
		return 0;
	}
		
	
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(j == 1)
			{
				dp[i][j] = dp[i-1][j] + v[i][j];
			}
			else if( j == i)
			{
				dp[i][j] = dp[i-1][j - 1] + v[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j - 1] , dp[i-1][j]) + v[i][j];
			}
		}
	}
	
	int maxNum = 0;
	for(int i = 1; i <= n; i++)
	{
		maxNum = max(maxNum , dp[n][i]);
	}
	
	cout << maxNum << endl;

	return 0;
}

