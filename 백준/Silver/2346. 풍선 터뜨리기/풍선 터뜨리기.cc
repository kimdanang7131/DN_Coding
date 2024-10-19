#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

typedef pair<int,int> Pos;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	
	deque<Pos> dq;
	
	for(int i = 0; i < n; i++)
	{
		int ballon;
		cin >> ballon;
		Pos pos = { i + 1 ,ballon };
		dq.push_back(pos);
	}
	
	while(!dq.empty())
	{
		int temp = dq.front().first;
		int idx  = dq.front().second;
		
		cout << dq.front().first << ' ';
		dq.pop_front();
		
		if(dq.empty())
			break;
			
		if(idx < 0)
		{
			idx *= -1;
			for(int i = 0; i < idx; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
		else
		{
			for(int i = 0; i < idx - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
	}

	return 0;
}
