#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int n ,m;
vector<int> bucketVec;

void Reverse(const int& a, const int& b)
{
	int size = b - a + 1;
	
	for(int i = 0; i < size / 2; i++)
	{
		int temp = bucketVec[b - 1 - i];
		bucketVec[b - 1 - i] = bucketVec[a - 1 + i];
		bucketVec[a - 1 + i] = temp;
	}
}

int main()
{	
	cin >> n >> m;
	
	bucketVec.assign(n,0);
	
	iota(bucketVec.begin(), bucketVec.end(),1);
	
	while(m--)
	{
		int a,b =0;
		
		cin >> a >> b;
		
		Reverse(a,b);
	}
	
	for(const int& i : bucketVec)
	{
		cout << i << " ";
	}
	
	return 0;
}