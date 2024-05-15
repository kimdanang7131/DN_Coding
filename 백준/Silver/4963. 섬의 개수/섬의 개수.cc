#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int w,h;
int ret;

		   // 상 하 좌 우 좌상 좌하 우상 우하 
int dx[] = { -1, 1,  0, 0, -1 ,  1, -1, 1 };
int dy[] = {  0, 0, -1, 1, -1 , -1,  1, 1 }; 


vector<vector<int>> boardVec;

void bfs(const int& x , const int& y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	boardVec[x][y] = 0;
	
	while(!q.empty())
	{
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		
		for(int i = 0; i < 8; i++)
		{
			int nx = dx[i] + mx;
			int ny = dy[i] + my;
			
			if( nx < 0 || ny < 0 || nx >= h || ny >= w)
				continue;
			if(boardVec[nx][ny] == 0)
				continue;
			if(boardVec[nx][ny] == 1)
			{		
				boardVec[nx][ny] = 0;
				q.push({nx,ny});
			}
		}
	}
}

void Reset()
{
	boardVec.assign(h,vector<int>(w,0));
	ret = 0;
}

int main()
{	
	do
	{
		cin >> w >> h;
			
		if(w == 0 && h == 0)
			return 0;
			
		Reset();
		
		for(int i=0; i < h; i++)
		{
			for(int j=0; j < w; j++)
			{
				cin >> boardVec[i][j];
			}
		}
		
		for(int i=0; i < h; i++)
		{
			for(int j=0; j < w; j++)
			{
				if(boardVec[i][j] == 1)
				{	
					bfs(i,j);
					ret++;
				}
			}
		}
		
		cout << ret << endl;
	}while(1);
	

	return 0;
}