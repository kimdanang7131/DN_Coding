#include <iostream>
#include <vector>

using namespace std;


void SelectionSort(vector<int>& arr, int n)
{
	int i,j,temp,maxIdx;
	i = j = temp = maxIdx = 0;
	
	
	for(i = 0; i < n-1; i++)
	{
		maxIdx = i;
		
		for(j = i + 1; j < n; j++)
		{
			if(arr[maxIdx] > arr[j])
			{
				maxIdx = j;
			}
		}
		
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	vector<int> gradeVec;
	
	int sum = 0;
	for(int i=0; i<5; i++)
	{
		int a;
		cin >> a;
		gradeVec.push_back(a);
		sum += a;
	}
	
	SelectionSort(gradeVec,gradeVec.size());
	
	int avg = sum / 5;
	int mid = gradeVec[2];
	
	cout << avg << endl << mid;
	
	return 0;
}