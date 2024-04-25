#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int t;
int n;

int main()
{
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		cin >> n;
		
		vector<pair<int,int>> scoreVec(n,{0,0}); 

		for(int j=0; j<n;  j++)
		{
			cin >> scoreVec[j].first;
			cin >> scoreVec[j].second;
		}
		
		sort(scoreVec.begin() , scoreVec.end());

		int temp = 0;
		int cnt = 1;
		
		for(int i=1; i<n; i++)
		{
			if(scoreVec[temp].second > scoreVec[i].second)
			{
				cnt++;
				temp = i;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
