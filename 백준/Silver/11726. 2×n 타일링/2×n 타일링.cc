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
	
	int n;
	
	cin >> n;
	
	vector<int> dpVec(n+1);
	dpVec[0] = 0;
	dpVec[1] = 1;
	dpVec[2] = 2;
	
	for(int i = 3; i<= n; i++)
	{
		dpVec[i] = (dpVec[i - 1] + dpVec[i - 2]) % 10007;;
	}
	
	cout<< dpVec[n] << endl;
	
	
    return 0;
}