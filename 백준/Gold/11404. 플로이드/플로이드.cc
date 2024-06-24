#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000

int n, m;
vector<vector<int>> boardVec;

int main()
{
	cin >> n >> m;
	boardVec.resize(n + 1, vector<int>(n + 1,INF));
	
	for (int i = 1; i <= n; i++) 
	{
		boardVec[i][i] = 0; 
	}
	
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		boardVec[a][b] = min(boardVec[a][b], c); 
	}
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
                boardVec[i][j] = min(boardVec[i][j] , boardVec[i][k] + boardVec[k][j]);
			}
		}
	}
	
	
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= n; j++) 
		{
			if(boardVec[i][j] == INF)
				cout << 0 << " ";
			else
				cout << boardVec[i][j] << " ";
        }
        cout << endl;
    }
	
	return 0;
}