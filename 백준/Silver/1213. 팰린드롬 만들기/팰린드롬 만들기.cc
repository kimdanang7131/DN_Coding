#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;


int main()
{	
	string str;
	cin >> str;
	
	map<char,int> alphaMap;
	
	for(int i=0; i <str.size(); i++)
	{
		alphaMap[str[i]] += 1;
	}

	char remain =';';
	queue<char> q;
	int cnt = 0;
	
	for(const auto& m : alphaMap)
	{
		if(m.second % 2 != 0)
		{
			cnt++;
			if(cnt >=2)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			
			remain = m.first;
		}
		
		for(int i=0; i < m.second / 2; i++)
			q.push(m.first);
	}
	
	stack<char> stk;
	while(!q.empty())
	{
		char c = q.front();
		stk.push(c);
		q.pop();
		
		cout << c;
	}
	
	if(remain != ';')
		cout << remain;
		
	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	
	return 0;
}