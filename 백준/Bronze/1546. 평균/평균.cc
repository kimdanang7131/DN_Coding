#include <iostream>
#include <vector>

using namespace std;

// 점수 / M * 100 
int main()
{
	int n;
	cin >> n;
	
	vector<int> inputVec(n,0);
	
	int max = -1;
	for(int i=0; i<n; i++)
	{
		int temp = 0;
		cin >> temp;
		
		if( max < temp)
			max = temp;
			
		inputVec[i] = temp;	
	}
	

	
	float sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += (float)inputVec[i] / max * 100;
	}
	
	sum = sum / n;
	
	cout << sum << endl;
	
	return 0;
}