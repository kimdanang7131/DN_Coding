#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, order = 1;
    cin >> n;
    
    stack<int> stk;
    
    while (n--) 
    {
        int num;
        cin >> num;
        
        if (num == order) 
        {
            order++;
        } 
        else 
        {
            stk.push(num);
        }
        
        while (!stk.empty() && stk.top() == order) 
        {
            stk.pop();
            order++;
        }
    }
    
    if (stk.empty()) 
        cout << "Nice";
    else 
        cout << "Sad";
    
    return 0;
}