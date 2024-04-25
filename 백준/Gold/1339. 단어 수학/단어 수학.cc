#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int res;
int alpha[26];

bool cmp(string a, string b)
{
	return a.length() > b.length();
}

int main()
{
	int n;
	cin >> n;
	
	vector<string> v(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> v[i];
	}
	
	for(int i=0; i<v.size(); i++)
	{
		int pow = 1;
		for(int j = v[i].size() - 1; j>=0; j--)
		{
			int val = v[i][j] - 'A';
			alpha[val] += pow;
			pow *= 10;
		}
	}
	
	sort(alpha, alpha + 26);
	
	int num = 9;
	for(int i= 25; i>=0; i--)
	{
		if(!alpha[i])
			break;
		
		res += (alpha[i] * num);
		num--;
	}
	cout << res;
	
	return 0;
}