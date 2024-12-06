#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;


int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n;
	
	int ret  =0;
	for(int i = 1; i <= n; i++)
	{
		if(i < 100)
		{
			ret++;
			continue;
		}
		
		int num = i;
		
   	 	int a = num / 100;          
    	int b = (num / 10) % 10;    
    	int c = num % 10;           
		
		if(a - b == b - c)
			ret++;
		
	}
	
	cout << ret << endl;

	return 0;
} 