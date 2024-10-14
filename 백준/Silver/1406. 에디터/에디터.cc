#include <iostream>
#include <list>
using namespace std;


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	string s;
	cin >> s;
	
	int size = s.size();
	list<char> lst;
	
	for(int i=0; i< size; i++)
	{
		lst.push_back(s[i]);
	}
	auto it = lst.end();
	
	int n;
	cin >> n;
	
	while(n--)
	{
		char order;
		cin >> order;
		
		switch(order)
		{
			case 'P':
				char c;
				cin >> c;
				lst.insert(it,c);
				break;
			case 'L':
				if(it != lst.begin())
					it--;
				break;
			case 'D':
				if(it != lst.end())
					it++;
				break;
			case 'B':
				if(it != lst.begin())
				{
					auto temp = it;
					--temp;
					it = lst.erase(temp);	
				}
				break;
		}
	}
	
	for (char c : lst) 
		cout << c;
		
	cout << endl;
    return 0;
}
