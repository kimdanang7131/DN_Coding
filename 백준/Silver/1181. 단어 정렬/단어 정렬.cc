#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;

bool cmp(const string& a , const string& b)
{
	if(a.length() == b.length())
	{
		for(int i=0; i<a.length(); i++)
		{
			if(a[i] != b[i])
				return a[i] < b[i];
		}
	}
	else
		return a.length() < b.length();
}
 
int main()
{ 
	ios_base::sync_with_stdio(false);

	cin >> n;
	vector<string> wordVec;
	map<string,bool> wordMap;
	
	for(int i=0; i<n; i++)
	{
		string tmp;
		cin >> tmp;
		
		if(wordMap.count(tmp) > 0)
			continue;
		
		wordMap[tmp] = true;
	}
	
	for(const pair<string,bool>& p : wordMap)
	{
		wordVec.emplace_back(p.first);
	}
	
	sort(wordVec.begin() , wordVec.end() , cmp);
	
	for(const string& s : wordVec)
	{
		cout << s << endl;
	}
	
	return 0;
}