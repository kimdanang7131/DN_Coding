#include <iostream>
#include <vector>
using namespace std;

int n , k;
int fact[11];
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n >> k;
	
	fact[0] = fact[1] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		fact[i] = i * fact[i-1];
	}
	
	int ans = fact[n] / (fact[k] * fact[n-k]);
	
	cout << ans << endl;
	return 0;
}
