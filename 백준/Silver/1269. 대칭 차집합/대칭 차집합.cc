#include <iostream>
#include <vector>

using namespace std;

int n , m;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	
	cin >> n >> m;
	vector<bool> v(100000001);
	
	for(int i=0; i < n + m; i++)
	{
		int idx = 0;
		cin >> idx;
		
		v[idx] = !v[idx];
	}
	
	int ans = 0;
	
	for(int i=0; i<100000001; i++)
	{
		if(v[i] == 1)
			ans++;
	}
	
	cout << ans;
	
	return 0;
}