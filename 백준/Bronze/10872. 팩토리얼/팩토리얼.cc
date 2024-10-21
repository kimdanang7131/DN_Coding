#include <iostream>
#include <vector>
using namespace std;

int n;
int fact[13];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	fact[0] = fact[1] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		fact[i] = i * fact[i-1];
	}
	
	cout << fact[n] << endl;
	
	return 0;
}
