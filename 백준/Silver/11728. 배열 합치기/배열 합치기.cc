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
int m;

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n >> m;
	
	vector<int> v1(n);
	vector<int> v2(m);
	
	for(int i=0; i<n; i++)
		cin >> v1[i];
		
	for(int i=0; i<m; i++)
		cin >> v2[i];
	
	sort(v1.rbegin(), v1.rend());
	sort(v2.rbegin(), v2.rend());
	
	while(!v1.empty() && !v2.empty())
	{
		int a = v1.back();
		int b = v2.back();
		
		if(a <= b)
		{
			cout << a << ' ';
			v1.pop_back();
		}
		else
		{
			cout << b << ' ';
			v2.pop_back();
		}
	}
	
	if(!v1.empty())
	{
		for(int i = v1.size() - 1; i >=0; i--)
			cout << v1[i] << ' ';
	}
	else if(!v2.empty())
	{
		for(int i = v2.size() - 1; i >=0; i--)
			cout << v2[i] << ' ';
	}
	

	
	return 0;
} 