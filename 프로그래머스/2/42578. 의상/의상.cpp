#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    unordered_map<string,int> combineMap;
    
    for(const vector<string>& rows : clothes)
    {
        string clothType = rows[1];
        
        combineMap[clothType]++;
    }

    for(pair<string,int> cMap : combineMap)
    {
        answer *= cMap.second + 1;
    }
    
    answer -= 1;
    return answer;
}