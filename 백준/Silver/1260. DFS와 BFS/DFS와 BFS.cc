#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int arr[1001][1001];
int visited[1001];
int N,M,V;

void dfs(int v)
{
	visited[v] = 1;
	cout << v << " ";
	
	for(int i = 1; i <= N; i++)
	{
		if(arr[v][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}		
	}
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);

	while(!q.empty())
	{
		int next = q.front();
		visited[next] = 1;
		cout << next << " ";
		q.pop();
		
		for(int i = 1; i <= N; i++)
		{
			if(arr[next][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}


int main()
{	
	int u,v;
	cin >> N >> M >> V;
	
	for(int i=0; i<M; i++)
	{
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	
	dfs(V);
	
	cout << endl;
	memset(visited,0,sizeof(visited));
	
	bfs(V);

	return 0;
}