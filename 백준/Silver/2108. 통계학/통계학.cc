#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int n;

#define MAX 500000
int arr[MAX + 1];


bool cmp(const pair<int,int>& p1, const pair<int,int>& p2)
{
	if(p1.second != p2.second)
		return p1.second > p2.second;
	
	return p1.first < p2.first;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	double san = 0.f;
	int mid = 0 , freq =  0, range = 0;
	
	
	map<int,int> freqMap;
	
	// 1
	for(int i=0; i <n; i++)
	{
		san += arr[i];
		freqMap[arr[i]]++;
	}
	san = round(san / n);
	if(san == -0)
		san = 0;
	
	// 2
	mid = arr[n / 2];
	
	// 3
	vector<pair<int,int>> v(freqMap.begin(), freqMap.end());
	sort(v.begin(), v.end(), cmp);
	
	if(v.size() == 1)
	{
		freq = v[0].first;
	}
	else 
	{
   		vector<int> modes; 
   		
  		int maxFreq = v[0].second; 
    	for (const pair<int,int>& p : v) 
		{
       		if (p.second == maxFreq) 	
        		modes.push_back(p.first); 
        }
		
		sort(modes.begin(), modes.end());
   		if (modes.size() > 1) 
		{ 
        	sort(modes.begin(), modes.end()); 
        	freq = modes[1]; 
    	} 
		else 
		{
        	freq = modes[0]; 
    	}
	}
	
	// 4
	if(n >= 2)
	{
		range = arr[n-1] - arr[0];
	}
	
	cout << san << endl;
	cout << mid << endl;
	cout << freq << endl;
	cout << range << endl;

	return 0;
}
