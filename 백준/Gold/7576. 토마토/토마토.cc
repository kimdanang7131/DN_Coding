#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m,n;
vector<vector<int>> tomatoVec;
	
		  // 상 하  좌  우  
int dx[] = { -1 , 1 , 0, 0};
int dy[] = {  0 , 0 ,-1, 1};


int ans = 0;

void bfs(const vector<pair<int,int>>& ripeVec)
{
	int rSize = ripeVec.size();
	queue<pair<int,int>> q;
	queue<pair<int,int>> countQ;
	
	for(int i=0; i< rSize; i++)
	{
		q.push({ripeVec[i].first , ripeVec[i].second});
	}
	
	int cnt = 1;
	
	while(!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		
	
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + cx;
			int ny = dy[i] + cy;
				
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if(tomatoVec[nx][ny] == -1)
				continue;
				
			if(tomatoVec[nx][ny] == 0)
			{
				tomatoVec[nx][ny] = 1;
				countQ.push({nx,ny});
			}
		}
	
		if(q.empty())
		{
			ans++;
			while(!countQ.empty())
			{
				q.push({countQ.front().first , countQ.front().second});
				countQ.pop();
			}
		}
	}
}


int main()
{	
	cin >> m >> n;
	
	tomatoVec.assign(n,vector<int>(m,0));
	
	vector<pair<int,int>> ripeVec;
	for(int i=0; i < n; i++)
	{
		for(int j=0; j < m; j++)
		{
			cin >> tomatoVec[i][j];
		
			if(tomatoVec[i][j] == 1)
				ripeVec.push_back({i,j});
		}
	}
	
	bfs(ripeVec);
	
	for(const vector<int>& v : tomatoVec)
	{
		for(const int& i : v)
		{	
			if(i == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << ans - 1 << endl;
	return 0;
}