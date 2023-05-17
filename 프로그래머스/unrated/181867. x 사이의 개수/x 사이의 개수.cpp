#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int i=0;
    
    for(const auto c : myString)
    {
        if(c == 'x')
        {
            answer.push_back(i);
            i=0;
        }
        else
            ++i;
    }
    
    if(myString[myString.size()-1] == 'x')
        answer.push_back(0);
    else
        answer.push_back(i);
    return answer;
}