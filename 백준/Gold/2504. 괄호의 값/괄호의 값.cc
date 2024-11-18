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

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	string str;
	cin >> str;
	
	
	stack<char> stk;
	
	int tmp = 1;
	int ans = 0;
	
	char prev;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == '(' || str[i] == '[')
		{
			stk.push(str[i]);
			
			if(str[i] == '(')
				tmp *= 2;
			else
				tmp *= 3;
		}
		else
		{
		 	if(str[i] == ')')
			{
				if(stk.empty())
				{
					cout << 0;
					return 0;
				}
				if(stk.top() == '[')
				{
					cout << 0;
					return 0;
				}
				stk.pop();
				
				
				if(prev == '(')
				{
					ans += tmp;
					tmp /= 2;
				}
				else
					tmp /= 2;
			}
			else
			{
				if(stk.empty())
				{
					cout << 0;
					return 0;
				}
				if(stk.top() == '(')
				{
					cout << 0;
					return 0;
				}
				
				stk.pop();
				
				if(prev == '[')
				{
					ans += tmp;
					tmp /= 3;
				}
				else
					tmp /= 3;	
			}	
		}
		prev = str[i];
	}
	
	if(!stk.empty())
	{
		cout << 0;
		return 0;
	}
		
	
	cout << ans << endl;
	
	return 0;
} 