#include <iostream>
#include <vector>

using namespace std;

int px[1001];
int py[1001];


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	for(int i=0; i<3; i++)
	{
		int x,y;
		cin >> x >> y;
		
		px[x]++;
		py[y]++;
	}


	int mx, my;
	mx = 0;
	my = 0;
	
	for(int i=0; i< 1001; i++)
	{
		if(px[i] == 1)
		{
			mx = i;
		}
		
		if(py[i] == 1)
		{
			my = i;
		}
	}
	
	cout << mx << " " << my << endl;
	

	return 0;
}