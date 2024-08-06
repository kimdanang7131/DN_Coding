#include <iostream>
#include <vector>

using namespace std;


int n,k;
int arr[10001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	cin >> n >> k;
	
	
	int maxNum = -1;
	while(n--)
	{
		int grade;
		cin >> grade;
		
		if(maxNum < grade)
			maxNum = grade;
			
		arr[grade] += 1;
	}
	
	int cnt = 0;
	int ans = 0;
	
	for(int i = maxNum; i >= 0; i--)
	{
		if(arr[i] > 0)
		{
			while(arr[i]--)
			{
				cnt++;
				ans = i;
				
				if(cnt == k)
				{
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	
	if(cnt < k)
		cout << ans << endl;
	
	return 0;
}