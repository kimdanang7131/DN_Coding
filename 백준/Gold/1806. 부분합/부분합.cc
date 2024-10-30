#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n,t;
int arr[1000001];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n >> t;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	int minNum = INF;
	
	int s,e;
	s = e = 0;

	int len = INF;
	int sum = 0;
	
	while(e < n)
	{
		sum += arr[e++];
		
		while(sum >= t)
		{
			minNum = min(minNum , sum);
			len =  min(len , e - s);
			sum -= arr[s++];
		}
	}
	
	if(minNum == INF)
		cout << 0 << endl;
	else
		cout << len << endl;
		
	return 0;
}
