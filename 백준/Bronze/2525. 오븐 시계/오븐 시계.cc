#include <iostream>

using namespace std;

int h,m;
int t;

int main()
{	
	cin >> h >> m;
	cin >> t;
	
	m += t;
	
	h +=  m / 60;
	m %= 60;
	
	if(h > 23)
	{
		h -= 24;
	}
	
	cout << h << " " << m;
	
	return 0;
}