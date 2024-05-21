#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> bucketVec;

int main()
{	
	cin >> n >> m;
	
	bucketVec.assign(n + 1,0);
	// 1 ~ n
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		
		cin >> a >> b >> c;
		
		for(int j = a; j <=b; j++)
		{
			bucketVec[j] = c;
		}
	}

	for(int i= 1; i< bucketVec.size(); i++)
	{
		cout << bucketVec[i] << " ";
	}
	cout << endl;
	
	return 0;
}