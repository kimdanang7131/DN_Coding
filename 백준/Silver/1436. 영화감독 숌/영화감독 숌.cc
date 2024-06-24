#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	int res = 665;
	string temp;
	
	for(int i=0; i < n; i++)
	{
		while(1)
		{
			res++;
			temp = to_string(res);
			
			if(temp.find("666") != - 1)
				break;
		}
	}
	
	cout << res << endl;
}