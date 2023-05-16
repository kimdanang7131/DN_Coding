#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(const auto c : myString)
    {
        if(c <= 108)
            answer+='l';
        else
            answer+=c;
    }
    return answer;
}