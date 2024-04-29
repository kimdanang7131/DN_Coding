#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	int n;
	cin >> n;
	
	vector<int> orderVec(n , 0);
	
	for(int i=0; i< n; i++)
	{
		cin >> orderVec[i];
	}
	
	int ans = 0;
	for(int i = n - 2; i >=0; i--)
	{
		if(orderVec[i+1] <= orderVec[i])
		{
			int temp = orderVec[i] - orderVec[i+1] + 1;
			
			ans += temp;
			orderVec[i] -= temp;
		}
	}

	cout << ans;
	return 0;
}
