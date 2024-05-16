#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int px,py;
int a, b;
int l;

		// 좌상 , 좌하 , 상좌 , 상우 , 하좌, 하우, 우상, 우하   
int dx[] = { -1 ,   1,   -2  ,  -2 ,    2  ,   2 ,  -1  ,   1  };
int dy[] = { -2 ,  -2,   -1  ,   1 ,   -1  ,   1 ,   2  ,   2  }; 


vector<vector<bool>> checkVec;

void bfs(const int& x , const int& y)
{
	queue<pair<pair<int,int> , int>> q;
	q.push({{x,y} , 0});
	checkVec[x][y] = true;
	
	vector<int> minVec;
	
	while(!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if(cx == px && cy == py)
		{
			minVec.push_back(cnt);
			break;
		}
		
		for(int i=0; i < 8; i++)
		{
			int nx = dx[i] + cx;
			int ny = dy[i] + cy;
		
			if(nx < 0 || ny < 0 || nx >= l || ny >= l)
				continue;
			if(checkVec[nx][ny] == true)
				continue;
			if(checkVec[nx][ny] == false)
			{
				checkVec[nx][ny] = true;
				q.push({{nx,ny}, cnt + 1});
			}
		}
	}
	
	if(minVec.size() > 0)
	{
			sort(minVec.begin(), minVec.end());
			cout << minVec.front() << endl;
	}
}


int main()
{	
	cin >> n;
		
	while(n--)
	{
		l = 0;
		cin >> l;
		checkVec.assign(l , vector<bool>(l,false));
		a = 0 , b = 0, px = 0, py = 0;	
		
		cin >> a >> b;
		cin >> px >> py;
		
		bfs(a,b);
	}
	return 0;
}