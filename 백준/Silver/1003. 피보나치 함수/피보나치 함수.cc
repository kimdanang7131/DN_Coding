#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	
	int t = 0;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		vector<pair<int, int>> dpPair;
		
		if(n <= 1)
		{
			dpPair.reserve(2);
		}
		else
			dpPair.reserve(n+1);
			
		dpPair[0] = {1,0};
		dpPair[1] = {0,1};
		
		for(int i = 2; i <= n; i++)
		{
			dpPair[i].first  = dpPair[i-1].first  + dpPair[i-2].first;
			dpPair[i].second = dpPair[i-1].second + dpPair[i-2].second;
		}
		
		cout << dpPair[n].first << " " <<  dpPair[n].second << endl;
	}

    return 0;
}