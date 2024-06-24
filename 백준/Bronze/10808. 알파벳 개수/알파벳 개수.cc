#include <bits/stdc++.h>

using namespace std;

int alpha[26];

string s;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> s;
	
	for(int i=0; i<s.size(); i++)
	{
		int c = s[i] - 'a';
		alpha[c]++;
	}
	
	for(int i=0; i < 26; i++)
		cout << alpha[i] << ' ';
	
	return 0;
}