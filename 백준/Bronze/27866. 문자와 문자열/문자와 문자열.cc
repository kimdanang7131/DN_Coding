#include <iostream>
using namespace std;


string s;
int n;

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> s;
	cin >> n;
	
	cout << s[n-1];
	
	return 0;
}