#include <iostream>
#include <vector>

using namespace std;


// 0 ~ 100
int main()
{	
	pair<int,int> pos;
	vector<vector<int>> boardVec(9 , vector<int>(9,0));
	
	int maxNum = -1;
	
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cin >> boardVec[i][j];
			
			if(boardVec[i][j] > maxNum)
			{
				maxNum = boardVec[i][j];
				pos = {i + 1,j + 1};
			}
		}
	}	

	cout << maxNum << endl;
	cout << pos.first  << " " << pos.second << endl;
	
	return 0;
}