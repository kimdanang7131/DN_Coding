#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(const string& a , const string& b)
{
	if(a.length() == b.length())
	{
		return a < b;
	}
	else
		return a.length() < b.length();
}
 
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();
	
	vector<string> wordVec(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> wordVec[i];
	}
	
	
	sort(wordVec.begin() , wordVec.end() , cmp);
	wordVec.erase(unique(wordVec.begin() , wordVec.end()), wordVec.end());
		
	for(const string& s : wordVec)
	{
		cout << s << '\n';
	}
	
	return 0;
}