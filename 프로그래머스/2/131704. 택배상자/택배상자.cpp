#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> deliveryStk;
    stack<int> StorageStk;
    
    int cnt = 1;
    for(int i=0; i< order.size(); i++)
    {
       bool check = false;
        
        for(int j = cnt; j <= order[i]; j++)
        {
            deliveryStk.push(j);
            cnt++;
        }
        
        if(deliveryStk.empty() == false && deliveryStk.top() == order[i])
        {
            answer++;
            check =true;
        }
        else
        {
            if(deliveryStk.empty() == false)
               StorageStk.push(deliveryStk.top());
        }
        
        if(deliveryStk.empty() == false)
           deliveryStk.pop();
        
        if(StorageStk.empty() == false && StorageStk.top() == order[i])
        {
            check =true;
            answer++;
            StorageStk.pop();
        }
        
        if(check == false)
            break;
    }
    return answer;
}