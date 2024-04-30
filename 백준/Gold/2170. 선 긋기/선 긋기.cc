#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;
	
	vector<pair<int,int>> pointVec(n , {0,0});
	
	for(int i=0; i<n; i++)
	{
		cin >> pointVec[i].first;
		cin >> pointVec[i].second;
	}
	
	sort(pointVec.begin(), pointVec.end());
	
	int start = pointVec[0].first;
	int end   = pointVec[0].second;
	
	int sum = 0;
	for(int i=1; i<n; i++)
	{
		if(pointVec[i].first <= end)
	    	end = max(end, pointVec[i].second);
		else
		{
			sum += abs( end - start );
			
			start = pointVec[i].first;
			end   = pointVec[i].second;
		}
	}
	
	sum += abs ( end - start );
	
	cout << sum << endl;

	return 0;
}