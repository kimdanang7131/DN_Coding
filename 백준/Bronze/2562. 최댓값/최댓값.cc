#include <iostream>
#include <vector>
using namespace std;

vector<int> maxVec;

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	
	for(int i=0; i<9; i++)
	{
		cin >> n;
		maxVec.push_back(n);
	}
	
	int maxIdx = 0;
	int maxNum = -1;
	
	for(int i=0; i<9; i++)
	{
		if(maxNum < maxVec[i])
		{
			maxNum = maxVec[i];
			maxIdx = i;
		}
	}

	cout << maxNum << endl << maxIdx + 1 << endl;
	return 0;
}