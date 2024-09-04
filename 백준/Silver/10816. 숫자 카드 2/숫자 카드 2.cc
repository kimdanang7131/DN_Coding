#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n , m;
  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	
	map<int,int> cardMap;
	
	cin >> n;
	
	while(n--)
	{
		int i;
		cin >> i;
		
		cardMap[i]++;
	}
	
	cin >> m;
	
	for(int i=0; i<m; i++)
	{
		int f = 0;
		cin >> f;
		
		if(cardMap.count(f) > 0)
		{
			cout << cardMap[f] << ' ';
		}
		else
		{
			cout << "0" << ' ';
		}
	}

	
	return 0;
}