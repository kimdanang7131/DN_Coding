#include <iostream>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	long long * distance = new long long[n-1];
	for(int i=0; i< n-1; i++)
		cin >> distance[i];
		
	long long* cost = new long long[n];
	for(int j=0; j<n; j++)
		cin >> cost[j];
	
	long long sum = 0;
	for(int k=0; k< n-1; k++)
	{
		if(cost[k] < cost[k+1])
			cost[k+1] = cost[k];
			
		sum += cost[k] * distance[k];
	}
	
	cout << sum;
	
	delete []distance;
	delete []cost;
		
	return 0;
}