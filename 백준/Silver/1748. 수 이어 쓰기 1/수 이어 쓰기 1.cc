#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

long long n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	if( n < 10)
	{
		cout << n;
		return 0;
	}
	
	int cnt = 0;
    
    for (int i = 1; i <= n; i *= 10) 
	{
		cnt += (n - i + 1); // 개수  
	}
    cout << cnt << endl;
    
    return 0;
}