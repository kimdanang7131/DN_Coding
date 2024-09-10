#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n , m;

  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	set<string> st;
	
	cin >> n >> m;
	
	while(n--)
	{
		string name;
		cin >> name;
		
		st.insert(name);
	}
	
	vector<string> ansVec;
	
	while(m--)
	{
		string name;
		cin >> name;
		
		if(st.count(name) > 0)
			ansVec.push_back(name);
	}
	
	if(ansVec.empty())
	{
		cout << 0 << endl;
		return 0;
	}
	
	sort(ansVec.begin() , ansVec.end());
	cout << ansVec.size() << endl;
	for(const string& s : ansVec)
	{
		cout << s << '\n';
	}

	
	return 0;
}