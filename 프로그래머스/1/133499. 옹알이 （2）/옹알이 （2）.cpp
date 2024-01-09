#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    const char* str[4] = {"aya" , "ye" , "woo" , "ma"};
    
    for(int i=0; i<babbling.size(); i++)
    {
        vector<string> dedupeVec;
        
        string temp = "";
        for(int j=0; j<babbling[i].size(); j++)
        {
            temp += babbling[i][j];
            
            for(int k=0; k<4; k++)
            {
                if(temp == str[k])
                {
                    dedupeVec.push_back(temp);
                    temp = "";
                    break;
                }
            }
        }
        
        if(!dedupeVec.size())
            continue;
        
        string prevTemp = dedupeVec[0];
        temp = dedupeVec[0];
        
        for(int i=1; i<dedupeVec.size(); i++)
        {
            if(dedupeVec[i] == prevTemp)
                break;
            
            prevTemp = dedupeVec[i];
            temp += dedupeVec[i]; 
        }
   
        if(temp == babbling[i])
            ++answer;
            
    }
    return answer;
}