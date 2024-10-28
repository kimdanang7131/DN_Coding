#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    int i = 0;
    for(; i < enemy.size(); i++)
    {
        n -= enemy[i];
        pq.push(enemy[i]);
        
        if(n < 0)
        {
            if(k > 0)
            {
                if(!pq.empty())
                {
                    n += pq.top();
                    pq.pop();
                }
                k--; 
            }
            else
                break;
        }
    }
    
    answer = i;
    return answer;
}