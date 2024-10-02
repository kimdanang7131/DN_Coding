#include <iostream>
#include <stack>
using namespace std;

int n;


int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(1)
	{
		string words;
		getline(cin,words);
		
		if(words == ".")
			break;
			
		stack<int> stk;
		
		bool isBalanced = true; 
        for (char c : words) 
		{
            if (c == '(' || c == '[') 
			{
                stk.push(c); 
            } 
			else if (c == ')') 
			{
                if (stk.empty() || stk.top() != '(') 
				{ 
                    isBalanced = false;
                    break;
                }
                stk.pop(); 
            } 
			else if (c == ']') 
			{
                if (stk.empty() || stk.top() != '[') 
				{ 
                    isBalanced = false;
                    break;
                }
                stk.pop(); 
            }
        }

        if (!stk.empty()) 
            isBalanced = false;

        if (isBalanced)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
	}
	return 0;
}