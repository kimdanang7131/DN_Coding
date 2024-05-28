#include <iostream>
using namespace std;

int n;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	int sum = 0;
	
	string s;
	cin >> s;
	
	for(int i=0; i<s.size(); i++)
	{
		sum += s[i] - '0';
	}
	
	cout << sum << endl;
	return 0;
}