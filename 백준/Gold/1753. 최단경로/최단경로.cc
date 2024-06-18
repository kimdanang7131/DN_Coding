#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAXNUM 20001
#define INF 98098098

int V,E,K;
vector<pair<int,int>> graphVec[MAXNUM];
int dist[MAXNUM];

void bfs()
{
	priority_queue<pair<int,int>> pq;
	dist[K] = 0;
	pq.push({0,K});
	
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < graphVec[cur].size(); i++)
		{
			int nCur  = graphVec[cur][i].first;
			int nCost = graphVec[cur][i].second;
			
			if(dist[nCur] > cost + nCost)
			{
				dist[nCur] = cost + nCost;
				pq.push({-dist[nCur] , nCur});
			}
		}
	}
	
	for(int i=1; i<=V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
}

int main()
{	
	cin >> V >> E >> K;
	
	for(int i=0; i < E; i++)
	{
		int u,v,w;
		cin >> u >> v>> w;
		
		graphVec[u].push_back({v,w});
	}
	
	for(int i=1; i<=V; i++)
		dist[i] = INF;
	
	bfs();
	
	
	return 0;
}