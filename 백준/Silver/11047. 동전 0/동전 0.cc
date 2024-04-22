#include <iostream>
#include <vector>

using namespace std;

int n;
int answer;
	
int main() 
{
	int k;
	cin >> n >> k;
	
	vector<int> coinVec(n,0);
	for(int i =0; i < n; i++)
	{
		cin >> coinVec[i];
	}
	
	int cnt = coinVec.size() - 1;
	while( k != 0  && cnt >=0)
	{
		answer += k / coinVec[cnt];
		k %= coinVec[cnt--];
	}
	
	cout << answer << endl;
	return 0;
}
