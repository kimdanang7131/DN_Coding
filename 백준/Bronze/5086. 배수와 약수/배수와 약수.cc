#include <iostream>

using namespace std;


string s[] = {"factor", "multiple" , "neither"};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while(1)
	{
		int a , b;
		cin >> a>> b;
		if( a == 0 && b ==0 )
			break;
		
		if(b % a == 0)
			cout << s[0] << endl;
		else if(a % b == 0)
			cout << s[1] << endl;
		else
			cout << s[2] << endl;	
	}
	
	return 0;
}