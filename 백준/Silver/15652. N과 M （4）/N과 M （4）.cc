#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
bool visit[9];

void BackTracking(int cnt)
{
	if(cnt == m)
	{
		for(int i=0; i<m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	
	for(int i = 1; i <= n; i++)
	{
		arr[cnt] = i;
		
		if(cnt >= 1 && arr[cnt-1] > arr[cnt])
			continue;
		
		BackTracking(cnt + 1); 
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	BackTracking(0);
}
