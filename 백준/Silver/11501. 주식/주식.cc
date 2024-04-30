#include <iostream>
#include <vector>


using namespace std;


int main()
{	
	int t;
	
	cin >> t;
	
	int temp  = 0;
	long long sum   = 0;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		vector<int> tradeVec(n,0);
		
		temp = 0;
		sum  = 0;
		
		for(int j=0; j <n; j++)
		{
			cin >> tradeVec[j];
		}
		
		for(int k = n - 1; k >=0; k--)
		{
			temp = max(temp , tradeVec[k]);
			sum += temp - tradeVec[k];
		}
		
		
		cout << sum << endl;
	}

	return 0;
}