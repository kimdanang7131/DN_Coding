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
	
	vector<int> sVec(n + 1); 
  	vector<vector<int>> dpVec(n + 1 , vector<int>(3, 0));   
	
	for(int i = 1; i <= n; i++)
		cin >> sVec[i];
	
	if(n == 1)
	{
		cout << sVec[1];
		return 0;
	}
	
	
	dpVec[1][1] = sVec[1];
	dpVec[1][2] = 0;
	
	dpVec[2][1] = sVec[2];
	dpVec[2][2] = sVec[1] + sVec[2];
	
	for(int i = 3; i<=n; i++) 
	{
		dpVec[i][1] = max(dpVec[i-2][1] , dpVec[i-2][2]) + sVec[i]; 
		dpVec[i][2] = dpVec[i-1][1] + sVec[i];
	}
	
	cout << max(dpVec[n][1] , dpVec[n][2]);
		
	return 0;
}

