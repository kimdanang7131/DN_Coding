#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	vector<int> cardVec(n,0);
	priority_queue<int, vector<int> , greater<int>> pq;
	
	for(int i=0; i<n; i++)
	{
		cin >> cardVec[i];
		pq.push(cardVec[i]);
	}
	
	int sum=0;
	while(pq.size() > 1)
	{
		int n1 , n2;
		
		n1 = pq.top() , pq.pop();
		n2 = pq.top() , pq.pop();
		
		sum += ( n1 + n2 );
		
		pq.push(n1 + n2);
	}
	
	cout << sum;
	return 0;
}
