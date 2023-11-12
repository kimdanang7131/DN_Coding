#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int start , end , order = -1;
    
    for(const vector<int>& cols : commands)
    {
        start = cols[0];
        end   = cols[1];
        order = cols[2] - 1;
        
        vector<int> temp;
        
        for(int i = start - 1; i < end; i++)
        {
            temp.push_back(array[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[order]);
    }
    
    return answer;
}