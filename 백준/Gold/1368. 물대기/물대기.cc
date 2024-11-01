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
int costVec[301];
vector<vector<int>> graphVec;
bool isused[301];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int cost;
		cin >> cost;
		
		costVec[i] = cost;
	}
	
	graphVec.resize(n + 1 , vector<int>(n + 1));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0;  j < n; j++)
		{
			cin >> graphVec[i][j];
		}
	}
	
	for(int i = 0; i < n + 1; i++)
	{
		graphVec[i][n] = costVec[i];
		graphVec[n][i] = costVec[i];
	}
	
	priority_queue< tuple<int,int,int> ,
				vector< tuple<int,int,int>>,
					greater<tuple<int,int,int>> > pq;
	// cost a b
	for(int i = 0; i < graphVec[0].size(); i++)
	{
		pq.push(make_tuple(graphVec[0][i], 0 , i));
	}
	isused[0] = true;
	
	int cnt = 0;
	int ans = 0;
	while(cnt < n)
	{
		int cost,a,b;
		tie(cost,a,b) = pq.top();
		pq.pop();
		
		if(isused[b] == true) continue;
		
		cnt++;
		ans += cost;
		isused[b] = true;
		
		for(int i = 0; i < graphVec[b].size(); i++)
		{
			if(isused[i] == false)
			{
				pq.push(make_tuple(graphVec[b][i], b , i));
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
