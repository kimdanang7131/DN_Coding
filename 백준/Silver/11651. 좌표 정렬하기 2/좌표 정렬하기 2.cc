#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

typedef pair<int,int> Point;


bool cmp(const Point& p1 , const Point& p2)
{
	if(p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	vector<Point> numVec(n);
	
	for(int i=0; i<n; i++)
	{
		cin >>numVec[i].first >> numVec[i].second;
	}
	
	stable_sort(numVec.begin() , numVec.end() , cmp);
	
	for(int i=0; i<n; i++)
	{
		cout << numVec[i].first << " " << numVec[i].second << '\n';
	}
	
	return 0;
}