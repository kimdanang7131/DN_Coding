#include <iostream>
using namespace std;

string s;
int t;

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--)
	{
		cin >> s;
		cout << s.front() <<  s.back() << endl;
	}
	
	return 0;
}