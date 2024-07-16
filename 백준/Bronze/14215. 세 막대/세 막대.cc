#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[3];


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for(int i=0; i<3; i++)
	{
		cin >> a[i];
	}
	
	sort(a , a+3);
	
	if(a[0] + a[1] > a[2])
		cout << a[0] + a[1] + a[2];
	else
		cout << (a[0] + a[1]) * 2 - 1;
	
	

	return 0;
}