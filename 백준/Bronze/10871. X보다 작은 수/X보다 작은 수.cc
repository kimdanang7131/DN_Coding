#include <iostream>
#include <vector>
using namespace std;

int n;
int x;

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> n >> x;
	
	vector<int> minVec;
	
	while(n--)
	{
		int num;
		cin >> num;
		
		if(num < x)
			minVec.push_back(num);
	}
	
	
	for(const int& i : minVec)
	{
		cout << i << " ";
	}

	return 0;
}