#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    vector<string> temp;
    
    for(auto str : intStrs)
    {
        temp.push_back(str.substr(s,l));
    }
    
    for(auto i_str : temp)
    {
        if(stoi(i_str) > k)
            answer.push_back(stoi(i_str));
    }
    return answer;
}