#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

long long dp[91];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i = 2; i <= 90; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	cout << dp[n] << endl;

    return 0;
}