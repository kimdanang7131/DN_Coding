#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff


// 4 3 7

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<int> stk;
	string str;
	
	int cnt = 1;
	
	while(n--)
	{
		int k;
		cin >> k;
		
		while(cnt <= k)
		{
			stk.push(cnt);
			cnt++;
			
			str += '+';
		}
		
		if(!stk.empty() && stk.top() == k)
		{
			stk.pop();
			str += '-';
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	
	for(const char& c: str)
	{
		cout << c << endl;
	}
	
    return 0;
}