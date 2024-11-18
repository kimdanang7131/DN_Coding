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
	
	stack<int> stk;
	
	int ans = 0;
	
	for(int i=0; i < str.size(); i++)
	{
		if(str[i] == '(')
		{
			stk.push(i);
		}
		else if(str[i] == ')')
		{
			if(!stk.empty())
			{
				int s = stk.top();
				stk.pop();
				
				if(s == i - 1) // lazer
				{
					ans += stk.size();
				}
				else // stick 
				{
					ans++;
				}
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
} 