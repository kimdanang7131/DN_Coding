#include <iostream>
#include <vector>
using namespace std;

#define MAX 250000


vector<bool> primeVec;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	
	primeVec.assign(MAX + 1, true);
	primeVec[0] = primeVec[1] = false;
	
	for(int i = 2; i * i <= MAX; i++)
	{
		if(primeVec[i])
		{
			for(int j = i*i; j <= MAX; j += i)
			{
				primeVec[j] = false;
			}
		}
	}
	
	
	do
	{
		int s;
		cin >> s;
		
		if(s == 0)
			break;
		
		int e = 2 * s;
		
		int cnt = 0;
		for(int i = s + 1; i <=e; i++)
		{
			if(primeVec[i] == true)
			{
				cnt++;
			}
				
		}
		
		cout << cnt << endl;
	}while(1);
	
	
    return 0;
}