#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 2100000000

int n,m;
int arr[1000001];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);
	
	int s,e;
	s = e =0;
	
	int minNum = INF; 
	
	while(s <= e && s < n)
	{
		if(arr[e] - arr[s] >= m)
		{
			minNum = min(minNum , arr[e] - arr[s]);
			s++;
		}
		else
		{
			e++;
		}
	}
	
	cout << minNum << endl;

	return 0;
}


// a + b = c