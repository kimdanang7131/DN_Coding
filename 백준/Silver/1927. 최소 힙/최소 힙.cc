#include <iostream>
#include <queue>
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
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	while(n--)
	{
		int op;
		cin >> op;
		
		if(op == 0)
		{
			
			
			if(pq.empty())
			{
				cout << "0" << endl;
			}
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(op);
		}
	}

    return 0;
}