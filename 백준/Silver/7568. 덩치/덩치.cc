#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	vector<pair<int,int>> v;
	
	
	for(int i=0; i<n; i++)
	{
		int x, y;
		
		cin >> x >> y;
		
		v.push_back({x,y});
	}
	
	
	for(int i = 0; i < n; i++)
	{
		int rank = 1;
		
		for(int j = 0; j < n; j++)
		{
			if(v[i].first < v[j].first && v[i].second < v[j].second)
			{
				rank++;
			}
		}
		cout << rank << ' ';
	}
    return 0;
}