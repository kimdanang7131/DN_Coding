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
    
    bool bStart = false;
    set<string> st;
    
    st.insert("ChongChong");
    int ans = 0;
    
    while(n--)
	{
		string a,b;
		cin >> a >> b;
		
		if(st.find(a) != st.end() || st.find(b) != st.end())
		{
			st.insert(a);
			st.insert(b);
		}
	} 
	cout << st.size()<< endl;
	return 0;
}
