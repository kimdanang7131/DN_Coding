#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int answer;

int main() 
{
	scanf("%d" , &n);
	
	vector<int> ropes(n,0);
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &ropes[i]);
	} 
	
	sort(ropes.rbegin() , ropes.rend());
	
	
	int sum = 0;
	sum    = ropes[0];
	answer = sum;
	
	int cnt = 1;
	for(int i=1; i < ropes.size(); i++)
	{
		int prevMax = answer;
		int min = ropes[i];
		cnt = i + 1;
		
		while( prevMax / cnt < min)
		{
			++prevMax;
		}
		
		answer = prevMax;
	}
	cout << answer << endl;
	
	return 0;
}
