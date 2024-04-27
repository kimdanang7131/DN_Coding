#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int num;


int main()
{
	cin >> num;
	
	vector<int> p, n;
	for(int i=0; i <num; i++)
	{
		int c;
		cin >> c;
		if(c > 0)
		 p.push_back(c);
		else
		 n.push_back(c);
	}
	
	sort(p.rbegin() , p.rend());
	sort(n.begin() , n.end());
	
	int ret = 0;
	if(p.size() % 2 != 0)
	{
		ret += p[p.size()-1];
	}
	
	for(int i=0; i< (int)p.size()-1; i += 2)
	{
		if(p[i+1] == 1) 
			ret += p[i] + p[i+1];
		else if(p[i+1] > 0 )
			ret += p[i] * p[i+1];			
	}
	
	if(n.size() % 2 != 0)
		ret += n[(int)n.size()-1];
	
	for(int i=0; i < (int)n.size() -1; i+=2)
		ret += n[i] * n[i+1];	
		
	cout << ret << endl;
	
	
	return 0;
}