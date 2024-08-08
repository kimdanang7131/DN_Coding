#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;

int main()
{ 
	cin >> n;
	
	vector<int> arrVec;
	
	while(n--)
	{
		int a;
		cin >> a;
		
		arrVec.push_back(a);
	}
	
	sort(arrVec.begin() , arrVec.end());
	
	for(const int& i : arrVec)
	{
		printf("%d\n",i);
	}
	
	return 0;
}