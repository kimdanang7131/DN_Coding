#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff
#define X first
#define Y second

int v,e;
int k;

vector<pair<int,int>> graphVec[20005];
int d[20005];

void dijkstra(const int& srt)
{
	for(int i = 1; i <= v; i++)
		d[i] = INF;
	
	priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
	d[srt] = 0;
	pq.push(make_pair(d[srt] , srt));
	
	while(!pq.empty())	
	{
		pair<int,int> cur = pq.top();
		pq.pop();
		
		if(d[cur.Y] != cur.X) continue;
		
		for(const pair<int,int>& nxt : graphVec[cur.Y])
		{
			if(d[nxt.Y] > d[cur.Y] + nxt.X)
			{
				d[nxt.Y] = d[cur.Y] + nxt.X;
				pq.push(make_pair(d[nxt.Y], nxt.Y));
			}
		}
	}
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> v >> e;
	cin >> k;
	
	for(int i=0; i<e; i++)
	{
		int a,b,c;
		
		cin >> a >> b >> c;
		
		graphVec[a].push_back(make_pair(c,b));
	}
	
	dijkstra(k);
	
	for(int i = 1; i <=v; i++)
	{
		if(d[i] == INF) cout << "INF" << endl;
		else	cout << d[i] << endl;
	}
	
	return 0;
}

