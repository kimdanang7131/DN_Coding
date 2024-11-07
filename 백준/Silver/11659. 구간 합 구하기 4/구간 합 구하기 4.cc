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
#define MAX 505

int n , m;



int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n >> m;
	
	vector<int> v(n);
	vector<int> dp(n + 1);
	
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];	
		dp[i+1] = dp[i] + v[i];
	}
	
	for(int i=0; i<m; i++)
	{
		int sum = 0;
		
		int a,b;
		cin >> a >> b;
		
		cout << dp[b] - dp[a -1] << endl;
	}
	
	return 0;
}

