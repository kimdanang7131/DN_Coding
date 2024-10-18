#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n, k;
	cin >> n  >> k;
	
	queue<int> q;
	for(int i = 1; i <= n; i++)
		q.push(i);
		
	
	vector<int> ans;
	 
	while(!q.empty())
	{
		for(int i = 0; i < k - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		
		int temp = q.front();
		q.pop();
		ans.push_back(temp);
	}
	
	
	string ret = "";
	ret+="<";
	
	for(int i=0; i<ans.size(); i++)
	{
		if(i == ans.size() - 1)
		{
			ret += to_string(ans[i]);
			ret += ">";
			break;
		}
		ret += to_string(ans[i]);
		ret += ", ";
	}

	cout << ret<< endl;
	return 0;
}
