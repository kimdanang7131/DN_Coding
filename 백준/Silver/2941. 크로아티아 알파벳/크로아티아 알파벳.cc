#include <iostream>
#include <vector>

using namespace std;


int main()
{	
	vector<string> strVec
	{
		"c=","c-","dz=","d-","lj","nj","s=","z="
	};	
	
	string str;
	cin >> str;
	
	int sub = 0;
	int add = 0;
	
	string temp;
	for(int j=0; j<str.size(); j++)
	{
		temp += str[j];
		
		for(int i=0; i<strVec.size(); i++)
		{
			if(temp.find(strVec[i]) != string::npos)
			{
				sub += strVec[i].size();
				add += 1;
				temp.clear();
				break;
			}
		}
	}
	
	int ans = str.size() - sub + add;
	cout << ans << endl;

	return 0;
}