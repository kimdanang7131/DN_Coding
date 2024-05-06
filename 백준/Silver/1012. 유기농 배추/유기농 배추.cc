#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;
int n , m , k;
vector<vector<int>> cabbageVec;
	
		  // 상 하  좌  우  
int dx[] = { -1 , 1 , 0, 0};
int dy[] = {  0 , 0 ,-1, 1};


void bfs(const int& x , const int& y)
{
	queue<pair<int,int>> q;
	cabbageVec[x][y] = 0;
	q.push({x,y});
	
	while(!q.empty())
	{
		int vx = q.front().first;
		int vy = q.front().second;
		q.pop();

		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + vx;
			int ny = dy[i] + vy;
			
			if( nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if( cabbageVec[nx][ny] == 0)
				continue;
			
			if( cabbageVec[nx][ny] == 1)
			{
				cabbageVec[nx][ny] = 0;
				q.push({nx,ny});
			}
		}
	}
}

int main()
{	
	cin >> t;
		
	while(t--)
	{
		cin >> n >> m >> k;
		
		cabbageVec.assign(n , vector<int>(m,0));
			
		for(int i=0; i<k; i++)
		{
			int x,y;
			
			cin >> x >> y;
			
			cabbageVec[x][y] = 1;
		}
		
		int ret = 0;
		
		for(int i=0; i < n; i++)
		{
			for(int j=0; j < m; j++)
			{
				if(cabbageVec[i][j] == 1)
				{
					ret++;
					bfs(i,j);
				}
			}
		}
		
		cout << ret << endl;
	}
	return 0;
}