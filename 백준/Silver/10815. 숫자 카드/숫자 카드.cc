#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;


int bSearch(const vector<int>& v , const int& length , const int& fValue)
{
	int pl = 0;
	int pr = length - 1;
	
	while(pl <= pr)
	{
		int pc = ( pl + pr ) / 2;
		
		if(v[pc] == fValue)
			return pc;
		else
		{
			if(v[pc] < fValue)
			{
				pl = pc + 1;
			}
			else
			{
				pr = pc - 1;
			}
		}
	}
	
	return -1;
}

  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	vector<int> cardVec(n);
	
	for(int i=0; i<n; i++)
	{
		cin >> cardVec[i];
	}
	
	sort(cardVec.begin() , cardVec.end());
	
	
	cin >> m;
	vector<int> findVec(m);
	
	for(int i=0; i<m; i++)
	{
		cin >> findVec[i];
	}
	
	
	for(const int& i : findVec)
	{
		if(bSearch(cardVec, (int)cardVec.size() , i) == -1)
			cout << 0 << ' ';
		else
			cout << 1 << ' ';
	}
	
	
	
	return 0;
}
