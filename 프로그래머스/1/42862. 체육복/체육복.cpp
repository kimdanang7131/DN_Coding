#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> clothVec(n + 1 , true);
    
    sort(lost.begin() , lost.end());
    sort(reserve.begin() , reserve.end());
    
    for(int i=0; i<lost.size(); i++)
    {
        int lostIdx = lost[i];
        clothVec[lostIdx] = false;
    }
    
    map<int,int> overlappedMap;
    
    for(int i=0; i<reserve.size(); i++)
    {
        bool isLost = false;
        int rsvIdx = reserve[i];
    
        if(clothVec[rsvIdx] == false)
            isLost = true;
        
        clothVec[rsvIdx] = true;
        
        if(overlappedMap.count(rsvIdx) > 0)
            continue;
        
        if(!isLost)
        {
            if(clothVec[rsvIdx - 1] == false)
            {
                clothVec[rsvIdx - 1] = true;
                continue;
            }
            else if(clothVec[rsvIdx + 1] == false)
            {
                clothVec[rsvIdx + 1] = true;
                overlappedMap[rsvIdx + 1]++;
            }
        }
    }
    
    clothVec[0] = false;
    
    for(const bool& b : clothVec)
    {
        if(b)
            answer++;
    }

    
    return answer;
}