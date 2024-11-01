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

int n;
int arr[1005];
int len[1005];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n;
	for(int i =0 ; i<n; i++)
	{
		cin >> arr[i];
	}
	
	for(int k = 0; k < n; k++)
	{
		len[k] = 1;
		for(int i=0; i < k; i++)
		{
			if(arr[i] < arr[k])
			{
				len[k] = max(len[k],  len[i] + 1);
			}
		}
	}
	
	int ans = *max_element(len, len + n);
	cout << ans << endl;
	
	return 0;
}

