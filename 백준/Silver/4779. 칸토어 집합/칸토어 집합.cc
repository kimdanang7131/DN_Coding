#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int n;

string MakeString(const string& str, const int& cnt)
{
	if(cnt == 0)
		return str;
	
	int size = str.size();
	int srt = size / 3;
	int end = srt * 2;
	
	string newStr = str;
	
	string s = newStr.substr(0  , srt);
	string e = newStr.substr(end);
	
	s = MakeString(s,cnt - 1);
	e = MakeString(e,cnt - 1);
	
	string ret;
	
	ret += s;
	ret += string(srt, ' ');
	ret += e;
	
	return ret;
}
  
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (cin >> n)
	{
		int strN = pow(3 , n);
		string s(strN, '-');
	
		s = MakeString(s, n);
		cout << s << endl;
	}
	
	
}
