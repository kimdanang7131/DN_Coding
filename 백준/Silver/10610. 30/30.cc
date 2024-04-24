#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	vector<int> nums;
	
	int check =0;
	
	string N;
	cin >> N;
	
	for(int i=0; i< N.size(); i++)
	{
		nums.push_back(N[i] - '0');
	}
	
	sort(nums.rbegin() , nums.rend());
	
	for(int i=0; i<nums.size(); i++)
	{
		check += nums[i];
	}
	
	if(check %3 != 0 ) cout << -1;
	else if(nums[nums.size()-1] != 0 ) cout << -1;
	else
	{
		for(const int& i : nums)
			cout << i;
	}
    
	return 0;
}