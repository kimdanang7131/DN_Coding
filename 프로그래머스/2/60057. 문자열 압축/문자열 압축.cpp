#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// 1000!
int solution(string s) 
{
    int answer = 1;
    int ret = 1005;
    
    if(s.size() == 1)
    {
        return 1;
    }
    while(answer < s.size())
    {
        int cnt = s.size() / answer;
        int remain = s.size() % answer;
        
        string word = "";
        string prev = s.substr(0 , answer);
        vector<string> strVec;
        
        int base = 0;
        for(int i = 0; i < cnt; i++)
        {
            base = i * answer;
            string temp = s.substr(base , answer);
            
            if(prev == temp)
            {
                strVec.push_back(temp);
            }
            else
            {
                if(strVec.size() > 0)
                {
                    if(strVec.size() != 1)
                        word += to_string(strVec.size());
                    
                    word += strVec[0];
                    strVec.clear();
                    strVec.push_back(temp);
                }
            }
            prev = temp;
        }
        
        if(remain > 0)
        {
            string temp = s.substr(cnt * answer);
            
            if(prev == temp)
            {
                strVec.push_back(temp);
            }
            else
            {
                if(strVec.size() > 0)
                {
                    if(strVec.size() != 1)
                        word += to_string(strVec.size());
                    
                    word += strVec[0];
                    strVec.clear();
                    strVec.push_back(temp);
                }
            }
            prev = temp;
        }
        
        if(strVec.size() > 0)
        {
            if(strVec.size() != 1)
                word += to_string(strVec.size());
            
            word += strVec[0];
            strVec.clear();
        }
        
        ret = min(ret, (int)word.size());
        answer++;
    }
    
    answer = ret;
    
    return answer;
}