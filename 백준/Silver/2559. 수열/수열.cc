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
int k;


int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
		
	cin >> n >> k;
	
	vector<int> v(n);
	
	
	int sum = 0;
	int maxNum = -105;
	
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	for(int i=0; i<k; i++)
	{
		sum += v[i];
	}
	
	maxNum = sum;
	
	for(int i = k; i < n; i++)
	{
		sum += v[i];
		sum -= v[i - k];
		maxNum = max(maxNum , sum);
	}
	
	cout << maxNum << endl;

	return 0;
} 