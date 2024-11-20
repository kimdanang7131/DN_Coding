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

int n;

class cmp
{
	public:
		bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
		{
			if(p1.first == p2.first)
				return p1.second > p2.second;
			else
				return p1.first > p2.first;
		}
};

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
	
	while(n--)
	{
		int x;
		cin >> x;
		
		if(x == 0)
		{
			if(pq.empty())
				cout << 0 << endl;
			else
			{
				cout << pq.top().second << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push({abs(x), x});
		}
	}
	

	return 0;
} 