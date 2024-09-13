#include <iostream>
#include <vector>
#include <set>

using namespace std;


int GetStringCount(const string& s, const int& size)
{

	set<string> st;
	
	string tmp = "";
	int itv = 1;
	while(tmp != s)
	{
		for(int i=0; i < size; i++)
		{
			if(i + itv > size)
				break;
				
			tmp = s.substr(i,itv);
			st.insert(tmp);
		}
		
		itv++;
	}
	return st.size();
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s;
	cin >> s;
	
	int size = s.size();
	
	cout << GetStringCount(s,size) << endl;
	
    return 0;
}