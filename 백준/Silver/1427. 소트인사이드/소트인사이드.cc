#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


string s;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	stable_sort(s.rbegin() , s.rend());
	
	cout << s << endl;
	
	return 0;
}
