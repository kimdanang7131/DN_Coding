#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int n,m;
vector<int> bucketVec;

int main()
{	
	cin >> n >> m;
	
	bucketVec.assign(n ,0);
	
	iota(bucketVec.begin(),bucketVec.end(),1);
	

	// 1 ~ n
	for(int i=0; i<m; i++)
	{
		int a,b;
		
		cin >> a >> b;
		
		int temp       = bucketVec[a - 1];
		bucketVec[a-1] = bucketVec[b - 1];
		bucketVec[b-1] = temp;
	}

	for(int i= 0; i< bucketVec.size(); i++)
	{
		cout << bucketVec[i] << " ";
	}
	cout << endl;
	
	return 0;
}