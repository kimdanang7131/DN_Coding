#include <iostream>
#include <vector>


using namespace std;

long long ret[16];
int n;

int main()
{
	cin >> n;
	
	int srt = 3;
	int itv = 1;
	
	for(int i = 1; i <= n; i++)
	{
		ret[i] = srt * srt;
		
		itv  *= 2;
		srt = srt + ( itv );
	}
	
	
	cout << ret[n] << endl;
	return 0;
}