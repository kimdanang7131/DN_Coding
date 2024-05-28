#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


char alpha[26];
string s;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	
	memset(alpha,-1,sizeof(alpha));
	
	for(int i=0; i<s.size(); i++)
	{
        int c = s[i] - 'a';
        int idx = i;
        
        if (alpha[c] != -1) 
		{
			int temp = alpha[c];
            idx = min(temp, i);
        }
        alpha[c] = idx;
	}
	
	for(const int& i : alpha)
	{
		cout << i << " ";
	}
	
	return 0;
}