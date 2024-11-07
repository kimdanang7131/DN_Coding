#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int t;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> t;
	
	vector<int> dpVec(12);
	
	dpVec[1] = 1;
	dpVec[2] = 2;
	dpVec[3] = 4; 
	
	
	for(int i = 4; i<=11; i++)
	{
		dpVec[i] = dpVec[i-1] + dpVec[i-2] + dpVec[i-3];
	}
	
	
	for(int i =0; i<t; i++)
	{
		int idx;
		cin >> idx;
		
		cout << dpVec[idx] << endl;
	}

	
	return 0;
}

