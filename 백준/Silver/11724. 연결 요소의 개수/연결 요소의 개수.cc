#include <iostream>
#include <vector>

using namespace std;

int n , m;

int graph[1001][1001];
bool visit[1001];

int ans;

bool dfs(const int& v)
{
	if(visit[v] == true)
		return false;
		
	visit[v] = true;
	
	for(int i=1; i <= n; i++)
	{
		if(graph[v][i] == 1 && visit[i] == false)
		{
			dfs(i);
		}
	}
	
	return true;
}

int main()
{	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a ,b;
		
		cin >> a >> b;
		
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	for(int i =1; i <= n; i++)
	{
		if(dfs(i))
			++ans;
	}
	
	cout << ans << endl;
	return 0;
}
