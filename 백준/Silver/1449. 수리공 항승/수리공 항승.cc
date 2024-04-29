#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n; int l;
int main()
{	
	cin >> n >> l;
	
	vector<int> location(n,0);
	
	for(int i=0; i<n; i++)
	{
		cin >> location[i];
	}
	
	sort(location.begin() ,location.end());
	
	int start = location[0];
	int len = 0;
	int tape = 0;
	for(int i = 1;  i< n; i++)
	{
		if(l <= location[i] - start)
		{
			tape++;
			
			start = location[i];
		}
	}
	
	cout << tape + 1;
	
	return 0;
}
