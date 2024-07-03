#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int n;


void CheckPerfectNum(const int& n)
{	
	vector<int> yaksuVec;
	
	for(int i = 1; i <= n / 2; i++)
	{
		if(n % i == 0)
		{
			yaksuVec.push_back(i);
		}
	}
	
	int ret = accumulate(yaksuVec.begin() , yaksuVec.end(),0);
	
	if(ret == n)
	{
		cout << n << " = " << accumulate(next(yaksuVec.begin()), yaksuVec.end() , to_string(yaksuVec[0]), 
		[](string a, int b) -> string
		{
			return a + " + " + to_string(b);
		}) << endl;
	}
	else
	{
		cout << n << " is NOT perfect." << endl;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	
	while(1)
	{
		cin >> n;
		if(n == -1)
			return 0;
		
		CheckPerfectNum(n);
	}
	
	return 0;
}