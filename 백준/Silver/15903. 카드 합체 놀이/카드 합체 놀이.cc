#include <iostream>
#include <queue>

using namespace std;

int main()
{	
	int n , m;
	cin >> n >> m;
	
	priority_queue<long long, vector<long long>, greater<long long>> cardPQ;
	for(int i=0; i< n; i++)
	{
		long long temp;
		cin >> temp;
		cardPQ.push(temp);
	}
	
	int cnt = 0;
	while(cnt < m )
	{
		long long a = cardPQ.top();
		cardPQ.pop();
		
		long long b = cardPQ.top();
		cardPQ.pop();
		
		
		long long sum = a + b;
		
		cardPQ.push(sum);
		cardPQ.push(sum);
		cnt++;
	}
	
	long long ans = 0;
	while(!cardPQ.empty())
	{
		ans += cardPQ.top();
		cardPQ.pop();
	}

	cout << ans;
	return 0;
}