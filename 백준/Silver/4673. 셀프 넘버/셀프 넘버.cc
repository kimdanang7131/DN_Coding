#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 0x7ffffff
#define MAX 10000

int arr[MAX + 1];

void dn(int num)
{
	int sum = num;
	
	if(num < 10)
	{
		sum += num;
		arr[sum] = 1;
		return;
	}
	
	string temp = "";
	temp = to_string(num);
	
	for(int i=0; i<temp.size(); i++)
	{
		int single = temp[i] - '0';
		sum += single;
		
		if(sum > MAX)
			return;
	}
	
	arr[sum] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	
	for(int i = 1; i<MAX; i++)
	{
		dn(i);
	}
	
	for(int i = 1; i<MAX; i++)
	{
		if(arr[i] == 0)
			cout << i << endl;
	}
	
    return 0;
}