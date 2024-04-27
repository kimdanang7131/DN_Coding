#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int n;

int main()
{
	cin >> n;
	
	vector<pair<int,int>> classVec(n , {0,0});
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i=0; i<n; i++)
	{
		cin >> classVec[i].first;
		cin >> classVec[i].second;
	}
	
	sort(classVec.begin() , classVec.end());
	
    pq.push(classVec[0].second);
    for (int i = 1; i < classVec.size(); i++) 
	{
        if (classVec[i].first >= pq.top()) 
		{
            pq.pop();
            pq.push(classVec[i].second);
        }
        else 
		{
            pq.push(classVec[i].second);
        }
    }
    
    cout << pq.size();
    
    
	return 0;
}
