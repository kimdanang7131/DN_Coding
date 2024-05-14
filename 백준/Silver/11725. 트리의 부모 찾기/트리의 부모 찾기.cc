#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;


vector<int> graph[100001];
int visited[100001];
int d[100001];
int n;

void bfs()
{
	queue<int> q;
	
	q.push(1);
	visited[1] = true;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i=0; i<graph[x].size(); i++)
		{
			int node = graph[x][i];
			if(visited[node] == false)
			{
				d[node] = x;
				q.push(node);
				visited[node] = true;
			}
		}
	}
}

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	int a,b;
	for(int i=0; i< n-1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	bfs();

	for(int i=2; i<=n; i++)
	{
		cout << d[i] << '\n';
	}
	return 0;
}