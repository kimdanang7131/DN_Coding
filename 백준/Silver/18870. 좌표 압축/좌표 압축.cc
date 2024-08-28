#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

  
int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();
	
	
	vector<int> numVec;
	
	while(n--)
	{
		int a;
		cin >> a;
		
		numVec.push_back(a);
	}
	
	vector<int> tempVec = numVec;
	
	sort(numVec.begin() , numVec.end());
	numVec.erase(unique(numVec.begin() , numVec.end()) , numVec.end());
	
	
	for (const int& i : tempVec)
    {
         int temp = lower_bound(numVec.begin(), numVec.end(), i) - numVec.begin();
         cout << temp << " ";
    }
	return 0;
}