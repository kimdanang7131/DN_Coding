#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int answer;
	

bool cmp(const pair<int,int>& a , const pair<int,int>& b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	else
		return a.second < b.second;
}

int main() 
{
	cin >> n;
	
	int start , end = 0;
	
	vector<pair<int,int>> seVec(n,make_pair(0,0));
	for(int i=0; i<n; i++)
	{
		cin >> start >> end;
		
		seVec[i].first  = start;
		seVec[i].second = end;
	}
	
	stable_sort(seVec.begin() , seVec.end() , cmp);
	
	vector<pair<int,int>> meetRoomVec;
	meetRoomVec.push_back({seVec[0].first , seVec[0].second});
	int endTime = seVec[0].second;
	
	for(int i=1; i<seVec.size(); i++)
	{	
		if(seVec[i].first >= endTime)
		{
			meetRoomVec.push_back({seVec[i].first , seVec[i].second});
			endTime = seVec[i].second;
		}
	}
	
	cout << meetRoomVec.size() << endl;
	
	return 0;
}
