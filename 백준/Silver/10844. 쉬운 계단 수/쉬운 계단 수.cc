#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> dp(n+1, vector<int>(10,0));
    
    for(int i = 1; i <= 9; i++)
    	dp[1][i] = 1;
    
	for(int i = 2; i <=n; i++)
	{
		for(int j = 0; j <=9; j++)
		{
			if(j == 0)
			{
				dp[i][j] = dp[i-1][1];
			}
			else if(j == 9)
			{
				dp[i][j] = dp[i-1][8];
			}
			else
			{
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
			}
		}
	}
	
	int result = 0;
	for(int i = 0; i <= 9; i++)
	{
		result = (result + dp[n][i]) % 1000000000;
	}
	
	cout << result << endl;
	
    return 0;
}