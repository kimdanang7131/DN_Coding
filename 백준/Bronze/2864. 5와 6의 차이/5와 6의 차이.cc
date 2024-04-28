#include <iostream>
#include <string>

using namespace std;

string a,b;
int main()
{	
	cin >> a >> b;
	
	string minStrA = a;
	string minStrB = b;
	
	string maxStrA = a;
	string maxStrB = b;
	
	for(int i=0; i<a.size(); i++)
	{
		if(minStrA[i] == '5')
			maxStrA[i] = '6';
			
		if(maxStrB[i] == '5')
			maxStrB[i] = '6';
	}
	
	for(int j=0; j<b.size(); j++)
	{
		if(minStrA[j] == '6')
		 	minStrA[j] = '5';
		
		if(minStrB[j] == '6')
			minStrB[j] = '5';
	}
	int minRet = stoi(minStrA) + stoi(minStrB);
	int maxRet = stoi(maxStrA) + stoi(maxStrB);
	
	cout << minRet << " " << maxRet;
	
	return 0;
}
