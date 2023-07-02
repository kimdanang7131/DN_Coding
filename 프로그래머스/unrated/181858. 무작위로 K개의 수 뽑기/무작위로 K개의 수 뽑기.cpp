#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;    
     
    answer.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++)
    {
        bool chk = false;
        for(int j=0; j < answer.size(); j++)
        {
            if((answer[j] == arr[i]) || answer.size() >=k )
            {
                chk = true;
                break;
            }
        }
        if(!chk)
           answer.push_back(arr[i]);
    }
    
    for(int i=answer.size(); i<k; i++)
    {
        answer.push_back(-1);
    }
    


    return answer;
}