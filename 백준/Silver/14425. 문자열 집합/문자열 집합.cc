#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
int m;

  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	set<string> s1;
	vector<string> findVec(m);
	
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		s1.insert(s);
	}
		
	for(int i=0; i<m; i++)
		cin >> findVec[i];	
		
	
	int ret =0;
	
	for(int i=0; i<m; i++)
	{
		if(s1.find(findVec[i]) != s1.end())
		{
			ret++;
		}
	}
	
	cout << ret << endl;
	
	return 0;
}