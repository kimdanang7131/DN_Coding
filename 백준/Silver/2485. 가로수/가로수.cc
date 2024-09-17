#include <iostream>
#include <vector>
using namespace std;

int n;

int GCD(int a, int b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	vector<int> v(n);
	vector<int> diff;
	
	for(int i=0; i < n; i++)
	{
		cin >> v[i];
	}
	
	for(int i = 1; i < n; i++)
	{
		int itv = v[i] - v[i-1];
		diff.push_back(itv);
	}
	
	int gcd = diff[0];
	for(int i=0; i<diff.size(); i++)
	{
		gcd = GCD(diff[i], gcd);
	}
	
	int ret = 0;
	
	for(int i=0; i<diff.size(); i++)
		ret += ( diff[i] / gcd )- 1;

	
	cout << ret << endl;
    return 0;
}