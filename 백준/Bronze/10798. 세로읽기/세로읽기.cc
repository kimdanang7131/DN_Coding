#include <iostream>
#include <vector>

using namespace std;

string s;
vector<vector<char>> wordVec;

int main()
{	
	int n = 5;
	int maxSize = -1;
	
	wordVec.assign(5,vector<char>(0,0));
	for(int i=0; i<5; i++)
	{
		cin >> s;
		int size = s.size();
		
		if(maxSize < size)
		{
			maxSize = size;
		}
		wordVec[i].resize(size);
		
		for(int j=0; j<size; j++)
		{
			wordVec[i][j] = s[j];
		}
	}
	
	for(int i=0; i < maxSize; i++)
	{
		for(int j=0; j < wordVec.size(); j++)
		{
			if( i < wordVec[j].size())
				cout << wordVec[j][i];
		}
	}

	return 0;
}