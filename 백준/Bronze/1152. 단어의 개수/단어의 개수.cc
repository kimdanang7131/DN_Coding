#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int t;

int main()
{	
	string s;
	getline(cin,s);
	
	stringstream ss;
	ss.str(s);
	
	string temp;
	int cnt = 0;
	while(ss >> temp)
	{
		++cnt;
	}	

	cout << cnt << endl;
	
	return 0;
}