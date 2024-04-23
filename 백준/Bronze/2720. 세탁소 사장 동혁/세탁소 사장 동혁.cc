#include <iostream>
#include <vector>

using namespace std;

int n;
int answer;

int main() 
{
	scanf("%d" , &n);
	
	
	// * 100
	vector<int> exchangeVec{ 25 , 10 , 5, 1 };
	vector<vector<int>> changeVec(n,vector<int>(4,0));
	//vector<int> costVec(n,0);
	
	for(int i=0; i<n; i++)
	{
		int cost;
		cin >> cost;
		
		for(int j=0; j<4; j++)
		{
			changeVec[i][j] = cost / exchangeVec[j];
			cost %= exchangeVec[j];
		}
	}
	
	
	for(int i=0; i<changeVec.size(); i++)
	{
		for(int j=0; j<changeVec[i].size(); j++)
		{
			cout << changeVec[i][j] << " ";
		}
		
		if(i == changeVec.size() -1)
			break;
			
		cout << endl;
	}
	
	return 0;
}