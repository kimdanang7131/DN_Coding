#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	
	if(n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
		
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i % 5   == 0)  cnt++;
		if(i % 25  == 0)  cnt++;
		if(i % 125 == 0)  cnt++;				
	}

	cout << cnt << endl;

    return 0;
}