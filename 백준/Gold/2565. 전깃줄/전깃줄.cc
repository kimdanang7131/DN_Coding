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
#define MAX 505

int n;
int arr[MAX];

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		arr[a] = b;
	}
	
	
	vector<int> lisVec;
	for(int i=1; i < MAX; i++)
	{
		if(arr[i] > 0)
		{
			vector<int>::iterator it = lower_bound(lisVec.begin() , lisVec.end() , arr[i]);
			
			if(it == lisVec.end())
			{
				lisVec.push_back(arr[i]);
			}
			else
			{
				*it = arr[i];
			}
		}
	}
	
	cout << n - lisVec.size() << endl;
	
	return 0;
}

