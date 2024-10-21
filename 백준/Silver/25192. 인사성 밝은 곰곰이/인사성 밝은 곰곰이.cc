#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    vector<set<string>> vSet;
    int setIdx = 0;
    
    while(n--) 
    {
    	string str;
    	cin >> str;
    	
    	if(str == "ENTER")
    	{
    		set<string> newSet;
    		vSet.push_back(newSet);
    		
    		setIdx = vSet.size() - 1;
		}
		else
		{
			vSet[setIdx].insert(str);
		}
	}
	
	int ans = 0;
	
	for(int i=0; i<vSet.size(); i++)
	{
		ans += vSet[i].size();
	}
	
	cout << ans << endl;

	return 0;
}
