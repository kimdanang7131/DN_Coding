#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
int ans;

int main()
{
	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;

		map<char, int> alphaMap;
		bool check = false;

		string temp;
		char prev = s[0];
		alphaMap[prev] = 1;
		for(int i=1; i<s.size(); i++)
		{
			prev = s[i-1];

			if (alphaMap.find(s[i]) != alphaMap.end())
			{
				if (s[i] == prev)
				{
					continue;
				}

				check = true;
				break;
			}

			alphaMap[s[i]] = 1;
		}

		if (!check)
			ans++;
	}

	cout << ans << endl;
	return 0;
}