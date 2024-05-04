#include <iostream>
#include <vector>

using namespace std;

int graph[101][101];
int visited[101];

int ans;
int m, n;

void dfs(const int& start)
{
	visited[start] = 1;

	
	for(int i = 1; i <= m; i++)
	{
		if(graph[start][i] == 1 && visited[i] == 0)
		{
			ans++;
			dfs(i);
		}
	}
}

int main()
{	
	cin >> m >> n;
	
	for(int i = 0; i < n; i++)
	{
		int s ,e;
		
		cin >> s >> e;
		
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	
	dfs(1);
	
	cout << ans << endl;

	return 0;
}