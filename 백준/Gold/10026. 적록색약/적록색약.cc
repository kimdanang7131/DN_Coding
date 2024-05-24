#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n;

int dx[] = { -1, 1,  0, 0};
int dy[] = {  0, 0, -1, 1};

int alpha[3] = {82, 71, 66};

vector<vector<int>> boardVec;
vector<vector<int>> checkVec;

int a,b;
void bfs(const int& x, const int& y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	
	int alphaNum = 0;
	
	for(int i=0; i<3; i++)
	{
		if( alpha[i] == checkVec[x][y] )
		{
			alphaNum = alpha[i];
			break;
		}
	}
	
	while(!q.empty())
	{
		int mx = q.front().first;
		int my = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = mx + dx[i];
			int ny = my + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
				
			if(checkVec[nx][ny] == alphaNum)
			{
				checkVec[nx][ny] = 0;
				q.push({nx,ny});
			}
		}
	}
}

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	boardVec.assign(n,vector<int>(n,0));
	checkVec.assign(n,vector<int>(n,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			char c;
			cin >> c;
			boardVec[i][j] = c;
		}
	}

	checkVec = boardVec;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(boardVec[i][j] == 71)
				boardVec[i][j] = 82;
				
			if(checkVec[i][j] != 0)
			{
				bfs(i,j);
				a++;
			}
		}
	}
	
	checkVec = boardVec;
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(checkVec[i][j] != 0)
			{		
				bfs(i,j);
				b++;
			}
		}
	}
	
	cout << a << " " << b << endl;
	
	return 0;
}