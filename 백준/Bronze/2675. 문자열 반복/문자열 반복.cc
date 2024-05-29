#include <iostream>
#include <vector>

using namespace std;


int t;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	
	while(t--)
	{
		int r;
		string s;
		
		cin >> r >> s;
		
		for(int i=0; i<s.size(); i++)
		{
			for(int j=0; j<r; j++)
			{
				cout << s[i];
			}
		}
		
		cout << endl;
	}
	
	return 0;
}