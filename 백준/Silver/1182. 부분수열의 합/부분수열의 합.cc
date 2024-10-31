#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n , s;
int ret;
int arr[21];

void SubSequence(int cur, int tot)
{
	if(cur == n)
	{
		if(tot == s)
			ret++;
		return;
	}
	
	SubSequence(cur + 1, tot);
	SubSequence(cur + 1, tot + arr[cur]);
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	cin >> n >> s;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	SubSequence(0,0);
	if(s == 0)
		ret--;
		
	cout << ret;
	return 0;
}
