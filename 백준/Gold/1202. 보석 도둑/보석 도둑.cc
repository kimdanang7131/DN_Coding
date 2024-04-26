#include <iostream>
#include <queue>
using namespace std;


int main()
{
	// n == jewel  // k == bag count 
	int n , k; 
	
	cin >> n >> k;
	
	
	priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> jewelPQ;
		
	// jewel
	for(int i=0; i<n; i++)
	{
		int f , l;
		cin >> f;
		cin >> l;
		
		jewelPQ.push({f,l});
	}
	
	priority_queue<int , vector<int>, greater<int>> bagPQ;
	// bag
	for(int i=0; i<k; i++)
	{
		int bagCnt;
		cin >> bagCnt;
		bagPQ.push(bagCnt);
	}	

	long long sum =0;
	
	priority_queue<int> pq;
	
	while(!bagPQ.empty())
	{
		int maxWeight = bagPQ.top();
		bagPQ.pop();
		
		while(!jewelPQ.empty())
		{	
			int weight = jewelPQ.top().first;
			int price  = jewelPQ.top().second;
			
			if(weight > maxWeight)
				break;
			
			jewelPQ.pop();
			
			pq.push(price);
		}
		
		
		if(!pq.empty())
		{
 			sum += pq.top();
			pq.pop();
		}
	}
	
	cout << sum << endl;
	
	
	return 0;
}
