#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	vector<int> delayVec(n,0);
		
	for(int i =0; i< delayVec.size(); i++)
	{
		cin >> delayVec[i];
	}
	
	if(n == 1)
	{
		cout << delayVec[0] << endl;
		return 0;
	}
	
	sort(delayVec.begin() , delayVec.end());
	
	vector<int> answerVec(n,0);
	answerVec[0] = delayVec[0];
	
	for(int i = 1; i < delayVec.size(); i++)
	{
		answerVec[i] = delayVec[i-1] + delayVec[i];
		delayVec[i] = answerVec[i];
	}
	
	int sum = 0;
	
	for(const int& i : answerVec)
		sum += i;
	
	
	cout << sum << endl;
	
	return 0;
}