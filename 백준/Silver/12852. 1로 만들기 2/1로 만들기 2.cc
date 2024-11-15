#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int d[10000005];
int pre[10000005];
int n;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n;
	d[1] = 0;
	
	for(int i = 2 ; i <=n; i++)
	{
		d[i] = d[i-1] + 1;
		pre[i] = i - 1;
		
		if( i % 2 == 0 && d[i] > d[i/2] + 1)
		{
			d[i] = d[i/2] + 1;
			pre[i] = i / 2;
		}
		
		if( i % 3 == 0 && d[i] > d[i/3] + 1)
		{
			d[i] = d[i/3] + 1;
			pre[i] = i / 3;
		}
	}
	
	cout << d[n] << endl;
	
	cout << n << ' ';
	while(n != 1)
	{
		cout << pre[n] << ' ';
		n = pre[n];
	}
	
	return 0;
} 