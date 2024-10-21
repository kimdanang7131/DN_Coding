#include <iostream>
#include <vector>
using namespace std;

long long t , n , m;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		long long ans = 1;
		
        for(int i=0; i < n; i++)
        {
        	ans *= (m - i);
        	ans /= (i + 1);
		}
		cout << ans << endl;
	
	}
	return 0;
}
