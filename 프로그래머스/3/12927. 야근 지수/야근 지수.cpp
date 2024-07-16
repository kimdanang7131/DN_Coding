#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q;
    
    for(int i=0; i < works.size(); i++)
    {
        q.push(works[i]);
    }
    
    while(n > 0)
    {
        int t = q.top();
        q.pop();
        
        if(t == 0)
            break;
        
        t--;
        q.push(t);
        n--;
    }
    

    while(!q.empty())
    {
        int t = q.top();
        q.pop();
        
        answer += t * t;
    }
    
    return answer;
}