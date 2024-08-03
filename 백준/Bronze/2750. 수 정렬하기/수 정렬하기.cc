#include <iostream>
#include <vector>

using namespace std;

int n;


void InsertionSort(vector<int>& v, const int& n)
{
	int i,j,insData;
	
	
	for(i = 1; i < n; i++)
	{
		insData = v[i];
		
		for(j = i - 1; j >= 0; j--)
		{
			if(insData < v[j])
			{
				v[j+1] = v[j];
			}
			else
				break;
		}
		
		v[j+1] = insData;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	vector<int> v;
	
	while(n--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	InsertionSort(v , v.size());
	
	for(const int& i : v)
		cout << i << endl;
	
	return 0;
}