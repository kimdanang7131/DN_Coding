#include <iostream>
#include <vector>

using namespace std;

int x,y,w,h;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> x >> y >> w >> h;
	
	
	int a,b,c,d;
	a = h - y;
	b = w - x;
	c = y - 0;
	d = x - 0;
	
	cout << min(a,min(b,min(c,d))) << endl;


	return 0;
}