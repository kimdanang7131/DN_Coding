#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n , m;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	set<int> st;
	
	cin >> n >> m;
	
	
	while(n--)
	{
		int i = 0;
		cin >> i;
		
		st.insert(i);
	}
	
	int cnt = 0;
	
	while(m--)
	{
		int i = 0;
		cin >> i;
		
		if(st.count(i) > 0)
			cnt++;
			
		st.insert(i);
	}
	
	cout << st.size() - cnt;
	
	return 0;
}