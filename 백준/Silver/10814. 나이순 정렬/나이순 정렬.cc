#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std;

int n;

 bool cmp(const pair<int,string>& p1, const pair<int,string>& p2)
 {
 	return p1.first < p2.first;
 }
 
  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();
	
	// 나이 , 가입 순서 , 이름 
	int order = 0;
	
	map<int, vector<pair<int,string>>> infoMap;
	
	while(n--)
	{
		int age;
		string name;
		
		cin >> age >> name;
		
		infoMap[age].push_back({order++,name});
	}
	
	
	for(pair<int, vector<pair<int,string>>> p : infoMap)
	{
		
		int num = p.first;
		sort(p.second.begin() , p.second.end() , cmp);
		
		for(const pair<int,string> p2 : p.second)
		{
			cout << num << " "<< p2.second << '\n';
		}
	}

	
	return 0;
}