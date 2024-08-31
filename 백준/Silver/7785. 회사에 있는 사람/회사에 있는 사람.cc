#include <iostream>
#include <vector>
#include <map>


using namespace std;

int n;
  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	map<string,int , greater<string>> commuteMap;
	
	while(n--)
	{
		string name;
		string commute;
		
		cin >> name >> commute;
		
        if (commute == "enter") {
            commuteMap[name] = 1; 
        } 
		else if (commute == "leave") {
            commuteMap[name] = 0; 
        }
	}
	
	for(const pair<string,int>& p : commuteMap)
	{
		if(p.second == 1)
		{
			cout << p.first << '\n';
		}
	}
	
	return 0;
}