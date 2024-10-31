#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int t;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> t;
	
	
	for(int i=0; i < t; i++)
	{
		int k = 0;
		multiset<int> ms;
		
		cin >> k;
		
		while(k--)
		{
			char op;
			int n;
			cin >> op >> n;
			
			if(op == 'I')
			{
				ms.insert(n);
			}
			else if(op == 'D')
			{
				if(n == 1)
				{
					if(ms.size() > 0)
					{
						auto it = ms.end();
						ms.erase(prev(it));
					}
				}
				else if(n == -1)
				{
					if(ms.size() > 0)
						ms.erase(ms.begin());
				}
			}
		}
		
		if(ms.size() <= 0)
			cout << "EMPTY" << endl;
		else
		{
			auto it = ms.end();
			cout << *prev(it) << ' ' << *ms.begin() << endl;
		}
	}
    
	return 0;
}
