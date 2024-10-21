#include <iostream>
#include <vector>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	
	int ans = 0;
	ans = n * n - n;
	
	cout << ans << endl;
	return 0;
}
