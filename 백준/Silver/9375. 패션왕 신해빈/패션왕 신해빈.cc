#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int t;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		map<string,int> wearMap;
		
		string a , wearType;
		
		for(int i=0; i<n; i++)
		{
			cin >> a >> wearType;
			
			wearMap[wearType]++;
		}
		
		if(wearMap.empty())
		{
			cout << 0 << endl;
			continue;
		}
			
		
		int cnt = 1;
		for(const pair<string,int>& p : wearMap)
		{
			cnt *= (p.second + 1);
		}
		
		cout << cnt - 1 << endl;
	}
    
    return 0;
}