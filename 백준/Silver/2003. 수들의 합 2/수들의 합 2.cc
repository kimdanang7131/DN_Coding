#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n , m;
int arr[10001];

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	

	int sum = arr[0];
	
	int l = 0;
	int r = 0;
	
	int ret = 0;
	
 	while(r < n)
	{
		if(sum < m)
		{
			r++;
			if(r < n)
			{
				sum += arr[r];
			}
		}
		else if(sum > m)
		{
			sum -= arr[l++];
		}
		else if(sum == m)
		{
			sum -= arr[l];
			l++;
			r++;
			if( r < n)
				sum += arr[r];
			
			ret++;
		}
	}

	cout << ret << endl;
	
	return 0;
}
