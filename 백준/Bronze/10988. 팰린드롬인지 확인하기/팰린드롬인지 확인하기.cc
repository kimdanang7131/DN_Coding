#include <iostream>
#include <vector>

using namespace std;

string str;
int len;

int main()
{	
	getline(cin , str);
	len = str.length();
	
	for(int i=0; i< len / 2; i++)
	{
		if(str[i] != str [len - i - 1])
		{
			printf("0");
			return 0;
		}
	}
	
	printf("1");
	return 0;
}