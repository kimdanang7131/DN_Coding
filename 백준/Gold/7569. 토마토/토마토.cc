#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m,n ,h;
vector<vector<vector<int>>> tomatoVec;
	
		  // 위 아래  상 하  좌  우  
int dz[] = {  1 , -1 , 0 , 0 , 0, 0 };		  
int dx[] = {  0 ,  0 ,-1 , 1 , 0, 0 };
int dy[] = {  0 ,  0 , 0 , 0 ,-1, 1 };



int ans = 0;

void bfs(const vector<vector<pair<int,int>>>& ripeVec)
{

	queue<pair<pair<int,int>,int>> q;
	queue<pair<pair<int,int>,int>> countQ;
	
	for(int i=0; i< ripeVec.size(); i++)
	{
		for(int j=0; j< ripeVec[i].size(); j++)
		{
				q.push({{ripeVec[i][j].first , ripeVec[i][j].second} , i});
		}
	}
	
	int cnt = 1;
	
	while(!q.empty())
	{
		int cz = q.front().second;
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		q.pop();
		
	
		for(int i=0; i<6; i++)
		{
			int nz = dz[i] + cz;
			int nx = dx[i] + cx;
			int ny = dy[i] + cy;
				
			if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
				continue;
			if(tomatoVec[nz][nx][ny] == -1)
				continue;
				
			if(tomatoVec[nz][nx][ny] == 0)
			{
				tomatoVec[nz][nx][ny] = 1;
				countQ.push({{nx,ny} , nz});
			}
		}
	
		if(q.empty())
		{
			ans++;
			while(!countQ.empty())
			{
				q.push({{countQ.front().first.first , countQ.front().first.second} , countQ.front().second});
				countQ.pop();
			}
		}
	}
}


int main()
{	
	cin >> m >> n >> h;
	
	tomatoVec.assign(h,vector<vector<int>>(n,vector<int>(m,0)));
	vector<vector<pair<int,int>>> ripeVec(h);
	
	for(int k=0; k<h; k++)
	{
		for(int i=0; i < n; i++)
		{
			for(int j=0; j < m; j++)
			{
				cin >> tomatoVec[k][i][j];
			
				if(tomatoVec[k][i][j] == 1)
				{
					ripeVec[k].push_back({i,j});
				}
			}
		}	
	}
	
	bfs(ripeVec);
	
		
	for(const vector<vector<int>>& dv : tomatoVec)
	{
		for(const vector<int>& v : dv)
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
	}

	cout << ans - 1 << endl;
	return 0;
}