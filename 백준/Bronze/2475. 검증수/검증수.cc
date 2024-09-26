#include <iostream>
using namespace std;



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 5;
    int sum = 0;
    
    while(n--)
    {
    	int num;
    	cin >> num;
    	
    	sum += num*num;
	}
	
	sum %= 10;
	cout << sum << endl;


    return 0;
}