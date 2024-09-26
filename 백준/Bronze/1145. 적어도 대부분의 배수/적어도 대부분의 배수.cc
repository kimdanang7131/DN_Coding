#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    vector<int> v;
	while(n--)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	
	for(int i=1; i<=MAX; i++)
	{
		int count = 0;
		for(int j=0; j < v.size(); j++)
		{
			if(i % v[j] == 0)
				count++;
				
		}
		if(count >= 3)
		{
			cout << i << endl;
			break;
		}
	}

    return 0;
}