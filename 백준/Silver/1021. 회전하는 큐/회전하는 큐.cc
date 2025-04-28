#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m;
	cin >> n >> m;
	
	deque<int> dq(n); 
	
	for(int i=0; i<n; i++)
	{
		dq[i] = i;
	}
	
	queue<int> q;
	while(m--)
	{
		int out;
		cin >> out;
		
		q.push(out);
	}
	
	int ret = 0;
	while(!q.empty())
	{
		int key = q.front();
		q.pop();
		
		key--;
		
		// 기준점  
		int front = 0;
		for(int i=0; i<dq.size(); i++)
		{
			if(dq[i] == key)
			{
				front = i;
				break;
			}
		} 
		
		int back = (dq.size()) - front; 
		if(front < back)
		{
			for(int i=0; i < front; i++)
			{
				int temp = dq.front();
				dq.pop_front();
				
				ret++;
				dq.push_back(temp);
			}
			
			dq.pop_front();
		}
		else
		{
			for(int i=0; i< back; i++)
			{
				int temp = dq.back();
				dq.pop_back();
				
				ret++;
				dq.push_front(temp);
			}
			
			dq.pop_front();
		}

	}
	
	cout << ret << endl;
    
    return 0;
}