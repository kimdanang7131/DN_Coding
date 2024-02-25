#include <string>
#include <algorithm>
#include <map>

using namespace std;

void initMap(map<string,int>& strMap , string str)
{
    
    for(int i = 0; i < str.size() - 1; i++)
    {
        string temp = "";
         
        char first = str[i];
        char last  = str[i + 1];
        
        if( (isalpha(first) && isalpha(last)) ) // 두 문자가 모두 알파벳인 경우에만 처리
        {
            first = toupper(first);
            last  = toupper(last);
            
            temp += first;
            temp += last;
            
            strMap[temp]++;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
      
    map<string,int> str1Map;
    map<string,int> str2Map;
    map<string,int> unionMap;
    map<string,int> intersectMap;
    
    
    initMap(str1Map , str1);
    initMap(str2Map , str2);

    for(const pair<string,int>& m : str1Map)
    {
        if(str2Map.count(m.first) > 0)
        {
            int n1 = m.second;
            int n2 = str2Map[m.first];
            
            unionMap[m.first] = max(n1 , n2);
            intersectMap[m.first] = min(n1 , n2);
            continue;
        }
        
        unionMap[m.first] = m.second;
    }
    
    for(const pair<string,int>& m : str2Map)
    {
        if(str1Map.count(m.first) > 0)
        {
            int n1 = m.second;
            int n2 = str1Map[m.first];
            
            unionMap[m.first] = max(n1 , n2);
            intersectMap[m.first] = min(n1 , n2);
            continue;
        }
        
        unionMap[m.first] = m.second;
    }
        
        if(unionMap.empty())
        return 65536;
    

    int intersectCnt = 0;
    int unionCnt = 0;
    
    for(const pair<string,int>& s : unionMap)
        unionCnt += s.second;
    
    for(const pair<string,int>& s : intersectMap)
        intersectCnt += s.second;
    
    float result = intersectCnt / (float)unionCnt;
    
    result *= 65536;
    answer= result;
    

    return answer;
}