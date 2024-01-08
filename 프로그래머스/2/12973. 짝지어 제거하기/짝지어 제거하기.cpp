#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> dedupeStack;
    
    for(int i=0; i<s.size(); i++)
    {
        if(!dedupeStack.empty() && dedupeStack.top() == s[i])
        {
            dedupeStack.pop();
            continue;
        }
        dedupeStack.push(s[i]);
    }
    
    stack<char> remainStack;
    
    while (!dedupeStack.empty()) 
    {
        char currentChar = dedupeStack.top();
        dedupeStack.pop();

        if (!remainStack.empty() && remainStack.top() == currentChar) {
            remainStack.pop();
            continue;
        }

        remainStack.push(currentChar);
    }

    return remainStack.empty();
}