#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> houseVec;
	
		  // 상 하  좌  우  
int dx[] = { -1 , 1 , 0, 0};
int dy[] = {  0 , 0 ,-1, 1};


int ret;

void bfs(const int& x, const int& y)
{
	if(houseVec[x][y] == 0 || houseVec[x][y] == 2)
		return;
		
	houseVec[x][y] = 2;
	++ret;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue; 
			if(houseVec[nx][ny] == 0 || houseVec[nx][ny] == 2)
				continue;
			
			if(houseVec[nx][ny] == 1)
			{	
				++ret;
				houseVec[nx][ny] = 2;
				q.push({nx,ny});
			}
		}
	}
}

int main()
{		
	cin >> n;
	houseVec.resize(n, vector<int>(n,0));
	
	int ans = 0;
	
	for(int i=0; i<n; i++)
	{
		string temp;
		cin >> temp;
		for(int j=0; j<n; j++)
		{
			houseVec[i][j] = temp[j] - '0';
		}
	}
	
	
	vector<int> answerVec;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			bfs(i,j);
			if(ret > 0) 
			{
				answerVec.push_back(ret);
				ret = 0;
			}
		}
	}
	
	cout << answerVec.size() << endl;
	
	sort(answerVec.begin(), answerVec.end());
	
	for(int i=0; i<answerVec.size(); i++)
	{
		cout << answerVec[i] << endl;
	}

	return 0;
}