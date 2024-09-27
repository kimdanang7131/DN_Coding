#include <iostream>
#include <stack>
using namespace std;


int k;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<int> stk;
    cin >> k;
    while(k--)
    {
    	int n;
    	cin >> n;
    	
    	if(n == 0 && !stk.empty())
    		stk.pop();
    	else if(n != 0)
    	{
    		stk.push(n);
		}
	}
	
	int sum = 0;
	while(!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}
	
	cout << sum << endl;

    return 0;
}