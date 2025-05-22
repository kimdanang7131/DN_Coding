#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	vector<string> v;
	

	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		
		v.push_back(s); 
	}
	
	
	
	int size = v[0].size();
	set<string> st;
	
	int cnt = 0;
	bool check = false;
	for(int j = size -1; j >= 0; j--)
	{
		++cnt;
		check = false;
		for(int i=0; i<v.size(); i++)
		{
			string temp;
			temp = v[i].substr(j);
			
			if(st.count(temp) > 0)
			{
				check = true;
				break;
			}
			
			st.insert(temp);
		}
		
		if(check == false)
		{
			break;
		}
	}
	
	cout << cnt << endl;
	
	
	
    return 0;
}