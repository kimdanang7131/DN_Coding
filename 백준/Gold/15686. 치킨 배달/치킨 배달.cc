#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff

struct Point
{
	int x;
	int y;
};

vector<Point> hV;
vector<Point> pV;
vector<Point> tV;
int homeDist[101];

int n,m;

int ret = INF;

void SetMinDistance(const int& hSize)
{
	for(int i=0; i<hSize; i++)
	{
		homeDist[i] = INF;
	}
	
	for(int i=0; i<hSize; i++)
	{
		for(int j = 0; j < tV.size(); j++)
		{
			int dist = abs(tV[j].x - hV[i].x) + abs(tV[j].y - hV[i].y);
			homeDist[i] = min(homeDist[i], dist);
		}
	}
	
	int sum = 0;
		
	for(int i=0; i < hSize; i++)
	{
		sum += homeDist[i];
	}
	
	ret = min(ret,sum);
}


void BackTracking(int cnt, int idx , const int& hSize, const int& pSize)
{
	if(cnt == m)
	{
		SetMinDistance(hSize);
		return;
	}
	
	for(int i = idx; i < pV.size(); i++)
	{
		tV.push_back({pV[i].x , pV[i].y});
		BackTracking(cnt + 1, i + 1, hSize,pSize);
		tV.pop_back();
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		int op;
    		cin >> op;
    		
    		if(op == 1)
    			hV.push_back({i,j});
    		else if(op == 2)
    			pV.push_back({i,j});
		}
	}
	
	int hSize = hV.size();
	int pSize = pV.size();
		
	BackTracking(0,0,hSize,pSize);
	cout << ret << endl;

    return 0;
}