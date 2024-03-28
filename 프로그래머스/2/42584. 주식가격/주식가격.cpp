#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    stack<int> priceStk;
    stack<int> answerStk;
    
    for(int i = prices.size() - 1 ; i >= 0; i--)
    {
        int tour = prices[i];
        int cnt  = 0;
            
        stack<int> tempStk;
        
        priceStk.push(tour);
        
        while(priceStk.empty() == false)
        {
            int stkNum = priceStk.top();
            cnt++;
            
            if(tour > stkNum)
                break;
            
            priceStk.pop();
            tempStk.push(stkNum);
        }
        
        
        while(tempStk.empty() == false)
        {
            priceStk.push(tempStk.top());
            tempStk.pop();
        }
        

        answerStk.push(cnt - 1);
    }
    
    while(!answerStk.empty())
    {
        answer.push_back(answerStk.top());
        answerStk.pop();
    }
    return answer;
}