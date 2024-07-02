#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> yaksuVec;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	for(int i=1; i <= n / 2; i++)
	{
		if(n % i == 0)
		{
			yaksuVec.push_back(i);
			
		}
	}
	
	yaksuVec.push_back(n);
	

	if(k <= yaksuVec.size())
	{
		cout << yaksuVec[k - 1] << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	
	return 0;
}