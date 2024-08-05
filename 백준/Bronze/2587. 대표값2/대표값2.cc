#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


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
	
	stable_sort(gradeVec.begin(), gradeVec.end());
	
	
	int avg = sum / 5;
	int mid = gradeVec[2];
	
	cout << avg << endl << mid;
	
	return 0;
}