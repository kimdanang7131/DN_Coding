#include <iostream>
#include <vector>

using namespace std;

		// 상  하  좌  우  
int dx[] = {-1 , 1,  0, 0};
int dy[] = { 0 , 0, -1, 1};

int n;

vector<vector<int>> boardVec;
vector<vector<int>> checkVec;
int ans;

void dfs(const int& x , const int& y)
{
	for(int i=0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			if(checkVec[nx][ny] == 1)
			{
				checkVec[nx][ny] = 0;
				dfs(nx,ny);
			}
		}
	}
}

void reset()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			checkVec[i][j] = 0;
		}
	}
}

int main()
{	
	cin >> n;
	
	boardVec.assign(n , vector<int>(n ,0));
	checkVec.assign(n , vector<int>(n ,0));
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> boardVec[i][j];
		}
	}
	
	for(int h=0; h <= 100; h++)
	{
		int ret = 0;
		
		for(int i=0; i < n; i++)
		{
			for(int j=0; j < n; j++)
			{
				if(boardVec[i][j] < h)
					checkVec[i][j] = 0;
				else
					checkVec[i][j] = 1;
			}
		}
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(checkVec[i][j] == 1)
				{
					dfs(i,j);
					ret++;
				}
			}
		}
		
		ans = max(ans , ret);
		reset();
	}
	
	
	cout << ans;	
	return 0;
}