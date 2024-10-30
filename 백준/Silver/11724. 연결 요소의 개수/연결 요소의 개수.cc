#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n, m;
int ret;
vector<vector<int>> graphVec;
vector<bool> visitVec;

void BFS(const int& x)
{
	queue<int> q;
	q.push(x);
	visitVec[x] = true;
	
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for(int i = 0; i < graphVec[cur].size(); i++)
		{
			int next = graphVec[cur][i];
			
			if(!visitVec[next])
			{
				visitVec[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n >> m;
    graphVec.resize(n + 1);    
    visitVec.resize(n + 1, false);
    
    for(int i = 0; i < m; i++)
    {
    	int u, v;
		cin >> u >> v;
		
		graphVec[u].push_back(v);
		graphVec[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(visitVec[i] == false)
		{
			BFS(i);
			ret++;
		}
	}
		
		
	cout << ret << endl;
	return 0;
}
