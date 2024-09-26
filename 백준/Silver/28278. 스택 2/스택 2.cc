#include <iostream>
#include <stack>
using namespace std;

int n;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    stack<int> stk;
    
    while(n--)
    {
        int order;
        cin >> order;
        
        switch(order)
        {
            case 1:
            {
                int x;
                cin >> x;
                stk.push(x);
                break;
            }
                
            case 2:    
                if(!stk.empty())
                {
                    cout << stk.top() << "\n";
                    stk.pop();
                }
                else
                {
                    cout << "-1\n";
                }
                break;
                
            case 3:
                cout << stk.size() << "\n";
                break;

            case 4:
                cout << (stk.empty() ? "1" : "0") << "\n";
                break;
                
            case 5:
                if(!stk.empty())
                {
                    cout << stk.top() << "\n";
                }
                else
                {
                    cout << "-1\n";
                }
                break;
        }
    }

    return 0;
}