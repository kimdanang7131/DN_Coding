#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> n;
	
	vector<int> numVec(n,0);
	
	while(n--)
	{
		cin >> numVec[n];
	}
	
	int minNum , maxNum =0;
	
	minNum = *min_element(numVec.begin(), numVec.end());
	maxNum = *max_element(numVec.begin(), numVec.end());
	
	cout << minNum << " " << maxNum;
	return 0;
}