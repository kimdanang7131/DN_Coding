#include <iostream>
#include <queue>

using namespace std;


int n;

int main() 
{
	cin >> n;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> costPQ;
	
	vector<int> dist(n - 1,0);
	
	int remainDist = 0;
	
	for(int i=0; i < n - 1; i++)
	{
		cin >> dist[i];
		remainDist += dist[i];
	}
	
	vector<int> perCost(n,0);
	
	for(int i=0; i<n; i++)
	{
		cin >> perCost[i];
		
		costPQ.push({perCost[i],i});
	}
	
	
	pair<int,int> minPair(0,0);
	while(!costPQ.empty())
	{
		minPair.first  = costPQ.top().first;
		minPair.second = costPQ.top().second;
		costPQ.pop();
		
		if(minPair.second != n - 1)
			break;
	}
	
	int minIdx  = minPair.second;
	int minCost = minPair.first;
	
	unsigned long long sum = 0;
	for(int i=0; i < n; i++)
	{
		if(i == minIdx)
		{
			sum += remainDist * minCost;
			break;
		}
		
		// 최소가격 
		sum += dist[i] * perCost[i];
		remainDist -= dist[i];
	}
	
	cout << sum << endl; 
	
	return 0;
}