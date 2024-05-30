#include <iostream>
#include <vector>

using namespace std;

//int alpha[26];

int main()
{	
	int alpha[26] = 
	{
		3 , 3 , 3 , 4,  4, 4 ,
		5 , 5 , 5 ,	6 , 6,  6,
		7 , 7 , 7 , 8 , 8,  8, 8,
		9 , 9 , 9 , 10, 10, 10, 10
	};
	
	string s;
	cin >> s;
	
	int ret = 0;
	for(int i=0; i<s.size(); i++)
	{
		int c = s[i] - 'A';
		ret += alpha[c];
	}

	cout << ret;
	return 0;
}