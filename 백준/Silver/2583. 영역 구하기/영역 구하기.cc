#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,k;
vector<vector<int>> boardVec;

int dx[] = { -1 , 1 ,  0, 0};
int dy[] = {  0 , 0 , -1, 1};

int bfs(const int& x, const int& y)
{
	int cnt = 0;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty())
	{
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if(boardVec[ny][nx] == 0)
			{
				cnt++;
				boardVec[ny][nx] = 1;
				q.push({ny,nx});
			}
		}
	}
	
	return cnt;
}


int main()
{	
	cin >> m >> n >> k;
	
	boardVec.assign(m , vector<int>(n,0));
	
	for(int i=0; i<k; i++)
	{
		int a1,b1 , a2,b2;
		cin >> a1 >> b1 >> a2 >> b2;
		
		for(int i = b1; i < b2; i++)
		{
			for(int j= a1; j< a2; j++)
			{
				boardVec[i][j] = 1;
			}
		}
	}

	int area[100];
	int cnt = 0;
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(boardVec[i][j] == 0)
			{
				area[cnt++] = bfs(i,j);
				
				if(!area[cnt-1])
					area[cnt-1] = 1;
			}
		}
	}
	
	sort(area,area +cnt);
	cout<<cnt<< endl;
	for(int i=0; i<cnt; i++)
	{
		cout << area[i] << " ";
	}
	
	return 0;
}