#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graphVec[101];
vector<vector<int>> boardVec;
int visit[101];

int n;

bool dfs(const int& s , const int& e)
{
	visit[s] = true;
	
	for(int i=0; i<graphVec[s].size(); i++)
	{
		int x = graphVec[s][i];
		if(e == x)
		{
			return true;
		}
		
		if(visit[x] == false)
		{
			if(dfs(x,e))
				return true;
		}
	}
	
	return false;
}

int main()
{	
	cin >> n;
	
	boardVec.assign(n, vector<int>(n,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int a;
			cin >> a;
			
			if(a == 1)
			{
				graphVec[i].push_back(j);
				boardVec[i][j] = 1;
			}
		}
	}
	
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(dfs(i, j))
			{
				boardVec[i][j] = 1;
			}
			memset(visit, 0 ,sizeof(visit));
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << boardVec[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}