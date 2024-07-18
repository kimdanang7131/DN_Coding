#include <iostream>
#include <vector>

using namespace std;

int a, b;
int c,n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> a >> b;
	
	cin >> c >> n;
	
	int res = 1;
	
	if(c < a) res = 0;
	if((c - a) * n < b) res = 0;
	
	
	cout << res << endl;


	return 0;
}