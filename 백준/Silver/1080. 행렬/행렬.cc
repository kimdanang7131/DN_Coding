#include <iostream>
#include <vector>

using namespace std;

int n , m;
string a[50],b[50];

bool same()
{
	for(int i=0; i<n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void flip(int y,int x)
{
	for(int i= y; i < y +3; i++)
	{
		for(int j = x; j < x + 3; j++)
		{
			a[i][j] = a[i][j] == '0' ? '1' : '0';
		}
	}
}

void solution()
{
	int result = 0;
	
	for(int i=0; i<n-2; i++)
	{
		for(int j=0; j< m-2; j++)
		{
			if(a[i][j] != b[i][j])
			{
				flip(i,j);
				result++;
			}
		}
	}
	
	if(same())
		cout << result;
	else
		cout << -1;

}

int main()
{	
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	for(int i=0; i<n; i++)
	{
		cin >> b[i];
	}
	
	solution();
	

	return 0;
}