#include <iostream>
#include <vector>

using namespace std;

string str;

int main()
{
	cin >> str;
	
	int c0 = 0;
	int c1 = 0;
	
	int idx = 0;
	int flag = str.front() -'0';
	while(1)
	{
		if(flag == 0)
		{
			flag = 1;
			
			if(str.find_first_of('0', idx) != string::npos)
			{
				idx = str.find_first_of('0', idx);
				idx++;
				c0++;
				continue;
			}
			
		}
		else
		{
			flag = 0;
			
			if(str.find_first_of('1', idx) != string::npos)
			{
				idx = str.find_first_of('1', idx);
				idx++;
				c1++;
				continue;
			}
		}
		
		break;
	} 
	
	int minElem = min(c0,c1);
    cout << minElem;
	return 0;
}