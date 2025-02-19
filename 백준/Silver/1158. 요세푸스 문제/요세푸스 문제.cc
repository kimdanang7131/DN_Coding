#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n , k;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    queue<int> q;
    vector<int> v;
    
    
    for(int i=1; i<=n; i++)
    {
    	q.push(i);
	}
	
	cout << "<";
	while (q.size() > 1) 
	{
		for (int i = 1; i < k; i++) 
		{
			int tmp = q.front();
			q.pop(); 
			q.push(tmp); 
		}
		cout << q.front() << ", ";
		q.pop();
	}
    
   cout << q.front() << ">";
  
	
    return 0;
}