#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> Point;

bool compare(const Point& p1, const Point& p2)
{
	if(p1.first == p2.first)
	{
		return p1.second < p2.second;
	}
	else
		return p1.first < p2.first;
}

int n;

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	vector<Point> pointVec(n);
	
	for(int i=0; i<n; i++)
	{
		int a,b;
		cin >> a >> b;
		
		pointVec[i] = {a,b};
	}

	
	stable_sort(pointVec.begin() , pointVec.end() , compare);
	
	for(const Point& p : pointVec)
	{
		cout << p.first << " " << p.second << '\n';
	}
	
	return 0;
}