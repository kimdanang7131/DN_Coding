#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

int t;

vector<bool> primeVec;
vector<int> v;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> t;
	primeVec.assign(MAX + 1, true);
	primeVec[0] = primeVec[1] = false;
	
	
	for(int i = 2; i * i <= MAX; i++)
	{
		if(primeVec[i])
			for(int j = i * i; j <= MAX; j += i)
				primeVec[j] = false;
	}
	
	for(int i=2; i <= MAX; i++)
	{
		if(primeVec[i] == true)
			v.push_back(i);	
	}
	
	while(t--)
	{
		int num;
		cin >> num;
		
		int count = 0;
     
        for (int i = 0; v[i] <= num / 2; i++) 
		{
            int s = v[i];
            int e = num - s;
            
            if (primeVec[e]) 
			{
                count++;
            }
        }
		printf("%d \n", count);
	}

    return 0;
}