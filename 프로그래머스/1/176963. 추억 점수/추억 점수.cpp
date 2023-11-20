#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string,int> yearnMap;
    
    for(int i=0; i<yearning.size(); i++)
        yearnMap[name[i]] = yearning[i];
    
    for(const vector<string>& strings : photo)
    {
        int sum = 0;
        for(const string& string : strings)
        {
            sum += yearnMap[string];
        }
        answer.push_back(sum);
    }
    
    
    return answer;
}