#include <iostream>
#include <stack>
using namespace std;


int n;

void CheckPS(string ps)
{
	stack<char> stk;
	
	for(int i=0; i<ps.size(); i++)
	{
		char c = ps[i];
		
		if(stk.empty())
		{
			stk.push(c);
		}
		else
		{
			if(c == '(')
			{
				stk.push(c);
			}
			else
			{
				if(stk.top() == '(')
					stk.pop();
				else
					stk.push(c);
			}
		}
	}
	
	stk.size() > 0 ? cout << "NO" << endl : cout << "YES" << endl;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    while(n--)
    {
    	string s;
    	cin >> s;
    	CheckPS(s);
	}
    return 0;
}