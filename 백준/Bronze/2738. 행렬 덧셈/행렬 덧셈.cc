#include <iostream>
#include <vector>

using namespace std;

int n,m;

int main()
{	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	vector<vector<int>> aVec(n , vector<int>(m,0));
	vector<vector<int>> bVec(n , vector<int>(m,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> aVec[i][j];
		}
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin >> bVec[i][j];
		}
	}
	
	vector<vector<int>> ansVec(n , vector<int>(m,0));
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			ansVec[i][j] = aVec[i][j] + bVec[i][j];
		}
	}
	
	for(const vector<int>& v : ansVec)
	{
		for(const int & i : v)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	
	return 0;
}