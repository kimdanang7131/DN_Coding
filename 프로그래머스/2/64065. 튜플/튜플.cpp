#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


bool cmp(const pair<int,int>& a , const pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}


vector<int> solution(string s) {
    vector<int> answer;
    
    set<int> elemSet;
 
    bool isOpen = false;
    string temp = "";
    
    vector<vector<int>> tempVec;
    vector<int> tVec;
    

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{')
        {
            isOpen = true;
            continue;
        }
        else if(s[i] == '}')
        {              
            if(temp.length() > 0)
            {
               tVec.push_back(stoi(temp));
            }
            
            tempVec.push_back(tVec);
            
            temp = "";
            tVec.clear();
            
            isOpen = false;
        }
        
        
        if(isOpen)
        {
            if(s[i] == ',')
            {   
                if(temp.length() > 0)
                {
                   tVec.push_back(stoi(temp));
                }
                
                temp = "";
                
                continue;
            }
            
            temp += s[i];
        }
    }
    
    tempVec.pop_back();
    

        
    vector<pair<int,int>> orderVec;
    for(int i=0; i<tempVec.size(); i++)
    {
        orderVec.push_back({ i, tempVec[i].size()});
    }
    
    sort(orderVec.begin(), orderVec.end() , cmp);
    
    
    
    for(int i=0; i<tempVec.size(); i++)
    {
        int order = orderVec[i].first;
        
        for(int j=0; j < tempVec[order].size(); j++)
        {
            if(elemSet.find(tempVec[order][j]) == elemSet.end())
            {
                elemSet.insert(tempVec[order][j]);
                answer.push_back(tempVec[order][j]);
            }
        }
    }
 
        
    return answer;
}