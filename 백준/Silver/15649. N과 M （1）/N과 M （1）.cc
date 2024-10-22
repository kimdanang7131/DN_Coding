#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;

int n;
int m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	vector<int> v(n);
	iota(v.begin() , v.end() , 1);
	
	set<string> st;
	
	do
	{
		string temp;
		for(int i = 0; i < m; i++)
		{
			temp += v[i] + '0';
			temp += ' ';
			
		}
		st.insert(temp);
	}while(next_permutation(v.begin(), v.end()));
	
	for(const string& s: st)
		cout << s << '\n';
}
