#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff
#define MAX 10005

int arr[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
	cin.ignore();
	
	
	
	int first = MAX - 1;
	int last = first;
	
	while(n--)
	{
		string s;
		cin >> s;
		
		if(s == "push")
		{
			int x;
			cin >> x;
			cin.ignore();
			
			arr[first--] = x;
		}
		else if(s == "pop")
		{
			if(last == first)
			{
				cout << -1 << endl;
				continue;
			}
			
			cout << arr[last--] << endl;
		}
		else if(s == "size")
		{
			cout << last - first << endl;
		}
		else if(s == "empty")
		{
			if(last - first == 0)
				cout << 1 << endl;
			else if(last - first > 0)
				cout << 0 << endl;
		}
		else if(s == "front")
		{
			if(last - first == 0)
			{
				cout << -1 << endl;
				continue;
			}
			cout << arr[last] << endl;
		}
		else
		{
			if(last - first == 0)
			{
				cout << -1 << endl;
				continue;
			}
			cout << arr[first + 1] << endl;
		}
	}
	
    return 0;
}