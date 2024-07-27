#include <iostream>
#include <vector>

using namespace std;

int n;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a,b,c,d,e,f;
	
	cin >> a >> b >> c >> d >> e >> f;
	

	for(int i=-999; i<= 999; i++)
	{
		for(int j=-999; j<=999; j++)
		{
			if(a*i + b*j == c && d*i + e*j == f)
			{
				cout << i << " " << j << endl;
				break;
			}
		}
	}
	
	
	return 0;
}