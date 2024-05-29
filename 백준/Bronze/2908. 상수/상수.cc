#include <iostream>
#include <vector>

using namespace std;


void ReverseString(string& s)
{
	int size = s.size();
	for(int i=0; i< size / 2 ; i++)
	{
		char c          = s[size - i - 1];
		s[size - i - 1] = s[i];
		s[i]            = c;
	}
}

int main()
{	
	string a,b;
	cin >> a >> b;
	
	ReverseString(a);
	ReverseString(b);
	
	a > b ? cout << a : cout << b;
	
	return 0;
}