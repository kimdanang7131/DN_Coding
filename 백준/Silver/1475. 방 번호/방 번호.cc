#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

int num[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	while(n > 0)
	{
		int remain = n % 10;
		n /= 10;
		
		if(remain == 9)
			remain = 6;
			
		num[remain]++;
	}
	
	if(num[6] > 0)
	{
		int ret = 0;
		
		if(num[6] % 2 == 0)
		{
			ret = num[6] / 2;
		}
		else
		{
			ret = (num[6] / 2)+ 1;
		}
		
		num[6] = ret;
	}
	
	int ans = 0;
	
	for(int i = 0; i < 10; i++)
	{
		ans = max(ans, num[i]);
	}
	
	cout << ans << endl;

	
    return 0;
}