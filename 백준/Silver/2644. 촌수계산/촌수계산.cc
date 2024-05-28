#include <iostream>
#include <vector>

using namespace std;


vector<int> graph[101];
int visit[101];

int n,m;
int a,b;

int ret;


int dfs(const int& s , int cnt)
{
	visit[s] = 1;
	
	if(s == b)
	{
		return cnt;
	}
	
	for(int i=0; i<graph[s].size(); i++)
	{
		int x = graph[s][i];
		if(visit[x] == 0)
		{
			int result = dfs(x, cnt + 1);
			if (result != -1) 
                return result; 
		}
	}
	return -1;	
}	


int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	cin >> a >> b;
	cin >> m;
	
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin >> x >> y;
		
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	cout << dfs(a , 0) << endl;
	return 0;
}