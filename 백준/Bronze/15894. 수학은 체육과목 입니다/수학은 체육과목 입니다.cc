#include <iostream>
#include <vector>

using namespace std;

long n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	long a = n * 2;
	long b = n - 1;
	long c = n + 1;
	
	
	cout << a + b + c  << endl;
	

	return 0;
}