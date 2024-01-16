#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<char,int,greater<char>> xMap;
    map<char,int,greater<char>> yMap;
    
    for(int i=0; i<X.size(); i++)
    {
        xMap[X[i]]++;
    }
       
    for(int i=0; i<Y.size(); i++)
    {
        yMap[Y[i]]++;
    }
    
    
    for(char c = '9';  c >= '0'; c--)
    {
        if(xMap.count(c) > 0 && yMap.count(c) > 0)
        {
            int xCount = xMap[c];
            int yCount = yMap[c];
            
            int count = 0;
            count = xCount <= yCount ? xCount : yCount;
            
            for(int i=0; i<count; i++)
            {
                answer += c;
            }
        }
    }
    
    
    if(!answer.size())
        return "-1";
    
    if(answer[0] == '0')
        return "0";
    
    
    return answer;
}