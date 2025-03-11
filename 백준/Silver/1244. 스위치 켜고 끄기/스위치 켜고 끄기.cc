#include <iostream>
#include <vector>
#include <deque>
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
	
	vector<int> v(n + 1);
	for(int i=1; i<=n; i++)
	{
		cin >> v[i];
	}
	
	int m;
	cin >> m;
	vector<pair<int,int>> vp;
	
	for(int i=0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		vp.push_back({a , b});
	}
	
	
	for(int i = 0; i < m; i++)
	{
		int gender = vp[i].first;
		int num    = vp[i].second;
		// 남자 
		if(gender == 1)
		{
			for(int j = num; j <= n; j += num)
			{
				v[j] = !v[j];
 			}
		}
		else if(gender == 2)// 여자 
		{
			int srt = num;
			int end = num;
			
			while(srt >= 1 && end <= n)
			{
				srt--;
				end++;
				
				if (v[srt] != v[end])
					break;
			}
			
			for(int i = srt + 1; i <= end - 1; i++)
			{
				v[i] = !v[i];
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << v[i] << ' ';
		
		if(i % 20 == 0)
			cout << endl;
	}

	
    return 0;
}