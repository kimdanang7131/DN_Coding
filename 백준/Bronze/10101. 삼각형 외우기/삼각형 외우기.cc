#include <iostream>
#include <vector>

using namespace std;


string s[4] = {"Equilateral" , "Isosceles" , "Scalene" , "Error"};


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int a1,a2,a3;
	int sum = 0;
	
	cin >> a1 >> a2 >> a3;
	
	sum = a1 + a2 + a3;
	int idx = 0;


	if(sum != 180)
		idx = 3;
	else if(a1 == 60 && a2 == 60 && a3 ==60 )
		idx = 0;
	else if(sum == 180 && (a1 == a2 && a2 != a3) || (a2 == a3 && a1 != a3) || (a1 == a3 && a3 != a2))
		idx = 1;
	else if(sum == 180 && a1 != a2 && a2 != a3 && a1 != a3)
		idx = 2;
	else
		return 0;
		
	
	cout << s[idx] << endl;	
	
	return 0;
}