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

int BFS()
{
	queue<pair<int,int>> q;
	q.push({n,0});
	
	while(!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(num == 1)
		{
			return cnt;
		}
		else if(num < 1)
		{
			break;
		}
		
		if(num % 3 == 0)
		{
			q.push({num / 3 , cnt + 1});
		}
		
		if(num % 2 == 0)
		{
			q.push({num / 2 , cnt + 1});
		}
		
		if(num - 1 >= 1)
		{
			q.push({num - 1 , cnt + 1});
		}
	}
	
	return -1;
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n;
	
	cout << BFS() << endl;
	
	
	

	
	return 0;
}

