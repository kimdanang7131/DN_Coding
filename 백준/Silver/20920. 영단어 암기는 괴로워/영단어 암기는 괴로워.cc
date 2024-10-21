#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int m; 


// 1 자주 나오는 단어 
// 2 길이 길수록  
// 3 알파벳 사전 순 
// M보다 긴 단언들만 외운다 

bool cmp(const pair<string,int>& p1,const pair<string,int>& p2)
{
	// 자주 
	if(p1.second == p2.second)
	{
		// 길이 
		if(p1.first.size() == p2.first.size())
		{
			// 사전 
			return p1.first < p2.first; 
		}
		
		return p1.first.size() > p2.first.size();
	}
	
	
	return p1.second > p2.second;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
	
	map<string,int> wordMap;
	
	while(n--)
	{
		string str;
		cin >> str;
		
		if(str.size() >= m)
		{
			wordMap[str]++;
		}
	} 
	
	vector<pair<string,int>> v(wordMap.begin() , wordMap.end());
	sort(v.begin() ,v.end() , cmp);
	
	for(const pair<string,int>& p : v)
	{
		cout << p.first << '\n';
	}
	return 0;
}
