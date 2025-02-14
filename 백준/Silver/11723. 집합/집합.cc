#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff


int arr[21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
	
	while(n--)
	{
		string s;
		cin >> s;
		
        if (s == "all")
        {
            fill(arr + 1, arr + 21, 1); 
            continue;
        }
        else if (s == "empty")
        {
            fill(arr + 1, arr + 21, 0); 
            continue;
        }
		
		int x;
		cin >> x;
		cin.ignore();
		
		if(s == "add")
		{
			arr[x] = 1;
		}
		else if(s == "remove")
		{
			arr[x] = 0;
		}
		else if(s == "check")
		{
			if(arr[x] == 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else
		{
			if(arr[x] == 1)
				arr[x] = 0;
			else
				arr[x] = 1;
		}
		
	}
	
    return 0;
}