#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


vector<int> graph[100001];
long long int visit[100001];
long long int depth[100001];

int n,m;
int srt;
int cnt = 1;

void dfs(const int& start , int count)
{
	depth[start] = count;
	visit[start] = cnt++;
	
	for(int i = 0; i < graph[start].size(); i++)
	{
		int x = graph[start][i];
		if(visit[x] == 0)
		{
			dfs(x , count + 1);
		}
	}
}

int main()
{	
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
	cin >> n >> m >> srt;
	
	for(int i=0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		
        graph[a].push_back(b);
        graph[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
	{
		sort(graph[i].begin() , graph[i].end());
	}
	memset(depth, -1, sizeof(depth));
	dfs(srt,0);
	
	long long int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += visit[i] * depth[i]; 
    }
	cout << sum << endl;
	return 0;
}