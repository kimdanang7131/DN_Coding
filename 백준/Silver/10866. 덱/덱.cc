#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> dq;
    
	cin >> n;
	
	
	while(n--)
	{
		cin.ignore();
		
		string op;
		cin >> op;
		
		if(op == "push_back")
		{
			int x;
			cin.ignore();
			cin >> x;
			
			dq.push_back(x);
		}
		else if(op == "push_front")
		{
			int x;
			cin.ignore();
			cin >> x;
			
			dq.push_front(x);			
		}
		else if(op == "front")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.front() << endl;
			}
		}
		else if(op == "back")
		{
			if(dq.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dq.back() << endl;
			}
		}
		else if(op == "empty")
		{
			if(dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(op == "size")
		{
			cout << dq.size() << endl;
		}
		else if(op == "pop_back")
	 	{
	 		if(dq.empty())
	 		{
	 			cout << -1 << endl;
			}
			else
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if(op == "pop_front")
		{
	 		if(dq.empty())
	 		{
	 			cout << -1 << endl;
			}
			else
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}			
		}
		
	}
	
    return 0;
}