#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int n,m;

int arr[1001];
vector<int> twoVec;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
    cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);
	
	for(int i=0; i<n; i++)
	{
		for(int j = i; j < n; j++)
			twoVec.push_back(arr[i] + arr[j]);
	}
	
	sort(twoVec.begin() , twoVec.end());
	
	for(int i = n - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(binary_search(twoVec.begin() , twoVec.end(), arr[i] - arr[j]))
			{
				cout << arr[i];
				return 0;
			}
		}
	}
	

	return 0;
}

