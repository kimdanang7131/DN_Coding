#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string temp ="";
    
    for(const auto c : my_string)
    {
        if(c == ' ')
        {
            answer.push_back(temp);
            temp="";
        }
        else
            temp+=c;
    }
    
    if(temp.size())
       answer.push_back(temp);
    
    return answer;
}