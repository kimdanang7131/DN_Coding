#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    
    for(const auto str : dic)
    {
        for(const auto c : spell)
        {
            if(str.find(c) != string::npos)
                answer=1;
            else
            {
                answer=2;
                break;
            }
        }
        
        if(answer == 1)
            break;
    }
    return answer;
}