#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


vector<vector<int>> boardVec;
vector<vector<int>> copyVec;

int n,m;
int ans;

		 // 상 하 좌 우  
int dx[] = {-1, 1, 0 , 0};
int dy[] = { 0, 0, -1, 1};


void bfs()
{
	vector<vector<int>> spreadVec(n, vector<int>(m,0));
	spreadVec = copyVec;
	
	queue<pair<int,int>> q;
	
	for(int i=0; i <n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(copyVec[i][j] == 2)
			{
				q.push(make_pair(i,j));
			}
		}
	}
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4 ;i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if(spreadVec[nx][ny] == 0)
			{
				spreadVec[nx][ny] = 2;
				q.push(make_pair(nx,ny));
			}
		}
	}
	
	int cnt = 0;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(spreadVec[i][j] == 0)
				cnt++;
		}
	}
	
	ans = max(ans,cnt);
}

void Recursive(int cnt)
{
	if(cnt == 3)
	{
		bfs();
		return;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(copyVec[i][j] == 0)
			{
				copyVec[i][j] = 1;
				Recursive(cnt + 1);
				copyVec[i][j] = 0;
			}
		}
	}
}

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	boardVec.assign(n, vector<int>(m,0));
	copyVec.assign(n, vector<int>(m,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> boardVec[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(boardVec[i][j] == 0)
			{
				copyVec = boardVec;
				
				copyVec[i][j] = 1;
				Recursive(1);
				copyVec[i][j] = 0;
			}
		}
	}
	
	
	cout << ans << endl;
	return 0;
}