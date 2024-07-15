#include <iostream>
#include <vector>

using namespace std;


string s[4] = {"Equilateral" , "Isosceles" , "Scalene" , "Invalid"};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	int idx = -1;
	
	while(1)
	{
		int a,b,c;
	
		cin >> a >> b >> c;
		
		if(a == 0 && b == 0 && c == 0)
			return 0;
		
		int maxNum = max(a,max(b,c));
		int sum = a + b + c - maxNum;
		
		if(maxNum >= sum)
			idx = 3;
		else if(a == b && b == c)
			idx = 0;
		else if(a == b || b == c || c == a)
			idx = 1;
		else
			idx = 2;
			
		cout << s[idx] << endl;	
	}
	
	return 0;
}