#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    map<char,int> alphaMap;
    
    for(char c = 'a'; c <= 'z'; c++)
    {
        alphaMap[c]++;
    }
    
    for(int i=0; i<skip.size(); i++)
    {
        if(alphaMap.count(skip[i]) > 0)
            alphaMap.erase(skip[i]);
    }

    
    for(const char& c : s)
    {
        map<char,int>::iterator iter = alphaMap.find(c);
        
        for(int i=0; i<index; i++)
        {
            ++iter;
            
            if(iter == alphaMap.end())
                iter = alphaMap.begin();
        }
        answer += iter->first;
    }
    
    return answer;
}