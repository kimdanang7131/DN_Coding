#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


vector<string> solution(vector<string> players, vector<string> callings) {
    
    unordered_map<string,int> orderMap;
    
    for(int i=0; i<players.size(); i++)
        orderMap[players[i]] = i;
    
    for(int i=0; i<callings.size(); i++)
    {
        // unordered_map으로부터 받은 value Idx
        int fIdx = orderMap[callings[i]];
        int prev = fIdx - 1;
        
        // unordered_map swap
        orderMap[callings[i]]   = prev;
        orderMap[players[prev]] = fIdx;
        
        // vector swap
        string temp = players[prev];
        players[prev] = players[fIdx];
        players[fIdx] = temp;
    }
    
    return players;
}