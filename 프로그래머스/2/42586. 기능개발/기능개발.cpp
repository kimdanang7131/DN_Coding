#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int size = speeds.size();
    vector<int> periodVec(size);
    
    for(int i = 0; i < size; i++)
    {
        int progressNow = progresses[i];
        int speedNow    = speeds[i];
        
        int period = 0;
        
        while( progressNow < 100)
        {
            progressNow += speedNow;
            period++;
        }
        
        periodVec[i] = period;
    }
    
    int periodCount = 0;
    
    for(int i = 0; i < periodVec.size(); i++)
    {
        int curVal = periodVec[i];
        
        for(int j = i; j < periodVec.size(); j++)
            periodVec[j] -= curVal;
        
        if(periodVec[i] <= 0)
        {
           for(int k = i; k < periodVec.size(); k++)
           {
               if(periodVec[k] > 0)
                   break;
               
               periodCount++;
           }
        }
        
        answer.push_back(periodCount);
        i += periodCount - 1;
        
        periodCount = 0;
    }
    
    return answer;
}