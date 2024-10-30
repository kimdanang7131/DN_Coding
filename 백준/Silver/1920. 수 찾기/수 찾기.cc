#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int n,m;
int arr[1000001];

int bSearch(const int& target)
{
	int pl = 0;
	int pr = n - 1;
	int mid = (pl + pr) / 2;
	
	while(pl <= pr)
	{
		mid = (pl + pr) / 2;
		
		if(arr[mid] == target)
			return 1;
		else
		{
			if(arr[mid] < target)
				pl = mid + 1;
			else
				pr = mid - 1;
		}
	}
	
	return 0;
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);
		
	cin >> m;
	for(int i=0; i<m; i++)
	{
		int find = 0;
		cin >> find;
		
		cout << bSearch(find) << endl;
	}

	return 0;
}

