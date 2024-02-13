#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a , const pair<int,int>& b)
{
    if(a.second == b.second)
        return a.first < b.second;
    else 
        return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> dupeMap;
    
    for(const int& i : tangerine)
        dupeMap[i]++;
    
    vector<pair<int,int>> sortedMap(dupeMap.begin() , dupeMap.end());
    sort(sortedMap.begin() , sortedMap.end() , cmp);
    
    for(const pair<int,int> temp : sortedMap)
    {
        k -= temp.second;
        answer++;
        
        
        if(k <= 0)
            break;
    }
    
    for(int i=0; i<k; i++)
        ++answer;
    
    return answer;
}