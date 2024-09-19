#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

int n,m;
vector<bool> primeVec;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	primeVec.assign(MAX + 1, true);
	primeVec[0] = primeVec[1] = false;
	
	
	for(int i = 2; i*i <= MAX; i++)
	{
		if(primeVec[i])
		{
			for(int j = i * i; j <= MAX; j += i)
			{
				primeVec[j] = false;
			}
		}
	}
	
	for(int i = n; i <= m; i++)
	{
		if(primeVec[i])
			printf("%d \n",i);
	}

    return 0;
}
