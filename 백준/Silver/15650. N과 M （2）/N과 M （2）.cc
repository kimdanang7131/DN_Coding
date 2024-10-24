#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n,m;
int arr[9];
bool visit[9];

void BackTracking(int idx,  int cnt)
{
	if(cnt == m)
	{
		for(int i = 0; i < cnt; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		
		return;
	}
	
	for(int i = idx; i <= n; i++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			arr[cnt] = i;
			BackTracking(i + 1, cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	BackTracking(1 , 0);
}
