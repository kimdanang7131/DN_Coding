#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n , m;
int ans;

vector<vector<int>> boardVec;

//           상   하   좌   우   
int dx[4] = {-1,   1,   0,   0};
int dy[4] = { 0,   0,  -1,   1};

int bfs(const int& x, const int& y)
{
	queue<pair<pair<int,int>,pair<int,bool>>> q;
	q.push({{x , y}, {1,false}});
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	
	while(!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		
		int w          = q.front().second.first;
		bool isCrashed = q.front().second.second;
		q.pop();
		
		if(cx == n - 1 && cy == m - 1)
		{
			return w;
		}
			
		
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + cx;
			int ny = dy[i] + cy;
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
		
           // 이동할 수 있는 경우
            if (boardVec[nx][ny] == 0 && !visited[nx][ny][isCrashed])
			{
                visited[nx][ny][isCrashed] = true;
                q.push({{nx, ny}, {w + 1, isCrashed}});
            }
            // 벽을 부수고 이동하는 경우
            if (boardVec[nx][ny] == 1 && !isCrashed && !visited[nx][ny][1])
			{
                visited[nx][ny][1] = true;
                q.push({{nx, ny}, {w + 1, true}});
            }
		}
	}
	
	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	cin.ignore();
	
	boardVec.assign(n , vector<int>(m,0));
	
	for(int i = 0; i < n; i++)
	{
		string line;
		getline(cin,line);
		
		for(int j = 0; j < m; j++)
		{
			boardVec[i][j] = line[j] - '0';
		}
	}
	
	ans = bfs(0,0);
	cout << ans << endl;
	
	return 0;
}