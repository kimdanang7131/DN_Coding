#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Point;

int n;

int main()
{ 
	cin >> n;
	
	vector<Point> pointVec(n);
	
	int a,b;
	
	for(int i=0; i<n; i++)
	{
		
		cin >> a >> b;
		
		pointVec[i] = {a,b};
	}
	
	sort(pointVec.begin() , pointVec.end());
	
	for(const Point& p : pointVec)
	{
		cout << p.first << " " << p.second << '\n';
	}
	
	return 0;
}