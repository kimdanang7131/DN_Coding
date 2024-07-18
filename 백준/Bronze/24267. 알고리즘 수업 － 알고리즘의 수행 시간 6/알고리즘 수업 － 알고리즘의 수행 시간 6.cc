#include <iostream>
#include <vector>

using namespace std;

long long n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	cout << ( n - 2) * ( n -1) * n / 6 << endl << 3 << endl;
	

	return 0;
}