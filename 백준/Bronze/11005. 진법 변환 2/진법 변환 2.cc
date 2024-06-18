#include <iostream>
#include <vector>

using namespace std;

int n;
int b;

int main()
{	
	cin >> n >> b;
	vector<int> baseVec;
	
	while(n > 0)
	{
		baseVec.push_back(n % b);
		n /= b;
	}
	
	for(int i= baseVec.size() - 1; i >= 0; i--)
	{
		int nb = baseVec[i];
		if(nb >= 10 && nb <= 35)
		{
			cout << char(nb + 'A' - 10);
			continue;
		}
		cout << nb;
	}

	
	return 0;
}