#include <iostream>
#include <queue>

using namespace std;


int n , k;
bool visit[100001];

int ans[3];

int main()
{	
	cin >> n >> k;
	
	queue<pair<int,int>> q;
	
	q.push({n,0});
	while(!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(x == k)
		{
			cout  << cnt;
			break;
		}
			
		if(x + 1 >=0 && x+1<100001)
		{
			if(visit[x + 1] == false)
			{
				visit[x + 1] = true;
				q.push({x + 1 , cnt + 1});
			}
		}
		
		if(x - 1 >=0 && x-1<100001)
		{
			if(visit[x  - 1] == false)
			{
				visit[x - 1] = true;
				q.push({x - 1 , cnt + 1});
			}
		}
			
		if(x * 2 >=0 && 2*x<100001)
		{
			if(visit[x * 2] == false)
			{
				visit[x * 2] = true;
				q.push({x * 2 , cnt + 1});
			}
		}
	}

	
	return 0;
}