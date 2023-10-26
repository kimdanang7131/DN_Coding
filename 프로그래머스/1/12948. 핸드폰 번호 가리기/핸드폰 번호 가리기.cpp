#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    string openNum = phone_number.substr(phone_number.size() - 4);
    
    for(int i=0; i<phone_number.size() - 4; i++)
        answer += "*";
    
    answer += openNum;
    
    return answer;
}