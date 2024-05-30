#include <iostream>
#include <vector>

using namespace std;

//int alpha[26];

int chess[6] = { 1, 1, 2, 2, 2, 8};
int ans[6];

int main()
{	
	
	
	for(int i=0; i < 6; i++)
	{
		int n;
		cin >> n;
		
		ans[i] = chess[i] - n;
	}
	
	for(int i=0; i< 6; i++)
	{
		cout << ans[i] << " ";
	}	
	return 0;
}