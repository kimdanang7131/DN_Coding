#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    long long target = 0;
    long long sumA = 0;
    long long sumB = 0;
    
    queue<int> q1;
    queue<int> q2;
    for(int i=0; i<queue1.size(); i++)
    {
        sumA += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i=0; i<queue2.size(); i++)
    {
        sumB += queue2[i];
        q2.push(queue2[i]);
    }
    
    target = sumA + sumB;
    target /= 2;
    
    int answer = 0;
    int maxCount = queue1.size() * 10;
    while(!q1.empty() && !q2.empty())
    {
        if(answer >= maxCount)
            return -1;
        
        if(sumA == target && sumB == target)
        {
            return answer;                
        }
        
        int input = 0;
        answer++;
        maxCount++;
        
        if(sumA > sumB)
        {
            input = q1.front();
            
            q1.pop();
            q2.push(input);
            
            sumA -= input;
            sumB += input;
        }
        else if( sumA < sumB )
        {
            input = q2.front();
            
            q2.pop();
            q1.push(input);
            
            sumA += input;
            sumB -= input;
        }
    }
    
    return -1;
}