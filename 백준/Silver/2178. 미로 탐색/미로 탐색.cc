#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> boardVec;

           // 상 하 좌 우 
int dx[] = { -1 , 1 ,  0, 0 };
int dy[] = {  0 , 0 , -1, 1};

int n , m;

int bfs(int x , int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty())
	{			
		pair<int,int> pos =  q.front();
		q.pop();
				
		for(int i=0; i<4; i++)
		{
			int nx = pos.first  +  dx[i];
			int ny = pos.second + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
				
			if(boardVec[nx][ny] == 0)
				continue;
		
			if(boardVec[nx][ny] == 1)
			{
				boardVec[nx][ny] = boardVec[pos.first][pos.second] + 1;
				q.push({nx,ny});
			
			}
		}
	}
	
	return boardVec[n - 1][m - 1];
}

int main()
{	
	cin >> n >> m;
	boardVec.resize(n,vector<int>(m,0));
	for(int i = 0 ; i < n; i++)
	{
		string input;
		cin >> input;
		
		for(int j = 0; j < input.size(); j++)
		{
			boardVec[i][j] = input[j] -'0';
		}
	}
	
	cout << bfs(0,0) << endl;

	return 0;
}