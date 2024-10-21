#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
    	cin >> v[i];
	}
	
	sort(v.begin() , v.end());
	cout << v.front() * v.back() << endl;

	return 0;
}
