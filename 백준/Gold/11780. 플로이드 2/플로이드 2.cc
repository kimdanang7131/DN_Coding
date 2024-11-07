#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
#define INF 1000000000

int n , m;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n >> m;
	
	vector<vector<int>> graphVec;
	graphVec.assign(n + 1, vector<int>(n + 1,INF));
	
	vector<vector<int>> nxtVec;
	nxtVec.assign(n + 1 , vector<int>(n + 1 ,INF));
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		cin >>a >> b >> c;	
			
		graphVec[a][b] = min(graphVec[a][b],c);
		nxtVec[a][b] = b;
	}
	
	for(int i=1; i<=n; i++)
		graphVec[i][i] = 0;
	

	
	
	for(int k = 1; k <=n; k++)
	{
		for(int i= 1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(graphVec[i][k] + graphVec[k][j] < graphVec[i][j])
				{
					graphVec[i][j] = min(graphVec[i][j], graphVec[i][k] + graphVec[k][j]);
					nxtVec[i][j] = nxtVec[i][k];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(graphVec[i][j] == INF) cout << 0 << ' ';
			else cout << graphVec[i][j] << ' ';
		}
		cout << endl;
	}
	
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(graphVec[i][j] == 0 || graphVec[i][j] == INF)
			{
				cout << 0 << endl;
				continue;
			}
				
				
			vector<int> path;
			int st = i;
			while(st != j)
			{
				path.push_back(st);
				st = nxtVec[st][j];
			}
			
			path.push_back(j);
			
			cout << path.size() << ' ';
			
			for(const int& idx : path)
				cout << idx << ' ';
			cout << endl;
		}
	}
	
	

	
	return 0;
}

