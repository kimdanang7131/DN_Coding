#include <iostream>
#include <queue>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	
	queue<int> q;
	for(int i=1; i<=n; i++)
	{
		q.push(i);
	}
	
	while(q.size() > 1)
	{
		if(!q.empty())
			q.pop();
		
		int temp = q.front();
		q.pop();
		
		q.push(temp);
	}
	
	
	if(!q.empty())
	{
		cout << q.front() << endl;
	}

    return 0;
}
