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

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	string t,p;
	getline(cin,t);
	getline(cin,p);
	
	int cnt = 0;
	int f = t.find(p);
	
	while(f != -1)
	{
		cnt++;
		f = t.find(p, f + p.size());
	}
	cout << cnt;
	
	return 0;
}
