#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n, m;
char alpha[27];

int lc[27];
int rc[27];
int p[27];

void PreOrder(int cur)
{
	cout << alpha[cur];
	if(lc[cur] != 0) PreOrder(lc[cur]);
	if(rc[cur] != 0) PreOrder(rc[cur]);
}

void InOrder(int cur)
{
	if(lc[cur] != 0) InOrder(lc[cur]);
	cout << alpha[cur];
	if(rc[cur] != 0) InOrder(rc[cur]);
}

void PostOrder(int cur)
{
	if(lc[cur] != 0) PostOrder(lc[cur]);
	if(rc[cur] != 0) PostOrder(rc[cur]);
	cout << alpha[cur];
}

int main()
{    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	for(int i = 1; i <= 26; i++)
	{
		alpha[i] = 'A' + i - 1;
	}
		
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
    	char rt, l , r;
    	
    	cin >> rt >> l >> r;
    	
    	if(l != '.') lc[rt- 'A' + 1] = l - 'A' + 1;
    	if(r != '.') rc[rt- 'A' + 1] = r - 'A' + 1;
    		
	}
	
	PreOrder(1); cout << endl;
	InOrder(1); cout << endl;
	PostOrder(1); cout << endl;
	
	return 0;
}
