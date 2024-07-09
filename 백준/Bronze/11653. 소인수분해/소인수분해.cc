#include <iostream>
#include <vector>

using namespace std;
#define MAX 10000001

int n;

vector<bool> primeVec;
vector<int> checkPrimeVec;

void EratosThenesThieve()
{
	primeVec.resize(MAX , true);
	
	primeVec[0] = primeVec[1] = false;
	
	for(int i = 2; i * i < MAX; i++)
	{
		if(primeVec[i])
		{
			for(int j = i * i; j < MAX; j += i)
			{
				primeVec[j] = false;
			}
		}
	}
	
	for(int i=0; i<MAX; i++)
	{
		if(primeVec[i] == true)
		{
			checkPrimeVec.push_back(i);
		}
	}
}

int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);
	
	EratosThenesThieve();
	cin >> n;
	
	if(n == 1)
		return 0;
	
	while(1)
	{
		int tmp = -1;
		for(int i = 0 ; i < checkPrimeVec.size(); i++)
		{
			if(n % checkPrimeVec[i] == 0)
			{
				tmp = checkPrimeVec[i];
				cout << tmp << endl;
				
				n /= tmp;
				break;
			}
		}
		
		if(tmp == -1)
			return 0;
	}

	return 0;
}