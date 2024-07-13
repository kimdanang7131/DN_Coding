#include <iostream>
#include <vector>

using namespace std;

#define MAX  10001
#define MIN -10001

int bx = MIN , by = MIN;
int mx = MAX , my = MAX;
int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	cin >> n;
	
	while(n--)
	{
		int a, b;
		cin >> a>> b;
		
		bx = max(a,bx);
		mx = min(a,mx);
		
		by = max(b,by);
		my = min(b,my);
	}
	
	cout << (bx - mx) * (by-my)<< endl;

	

	return 0;
}