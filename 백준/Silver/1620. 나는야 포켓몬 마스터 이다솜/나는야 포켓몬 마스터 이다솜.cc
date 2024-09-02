#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n , m;
  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<int,string> numMap;
	map<string,int> strMap;
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		string s;
		cin >> s;
		
		numMap[i+1] = s;
		strMap[s] = i + 1;
	}
	
	
	for(int i=0; i<m; i++)
	{
		string s = "";
		cin >> s;
		
		if(s.empty())
			continue;
			
		if(isdigit(s[0]))
		{
			int index = stoi(s);
			
			cout << numMap[index] << '\n';
		}
		else
		{
			cout << strMap[s] << '\n';
		}
	}
	
	return 0;
}
