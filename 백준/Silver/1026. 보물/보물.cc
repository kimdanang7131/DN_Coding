#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int answer;
	

int main() 
{
	cin >> n;
	
	vector<int> aVec(n,0);
	vector<int> bVec(n,0);
	
	for(int i=0; i<n; i++)
	{
		cin >> aVec[i];
	}
	
	for(int i=0; i<n; i++)
	{
		cin >> bVec[i];
	}
	
	priority_queue<int> pqA;
	priority_queue<int , vector<int> , greater<int>> pqB;
	
	for(int i=0; i < n; i++)
	{
		pqA.push(aVec[i]);
		pqB.push(bVec[i]);
	}
	
	
	while(!pqA.empty())
	{
		int a = pqA.top();
		int b = pqB.top();
		
		pqA.pop(); pqB.pop();
		
		answer += a * b;
	}
	
	cout << answer << endl;
	
	return 0;
}