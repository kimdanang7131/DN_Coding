#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    answer += myString.substr(0,myString.find_last_of(pat)+1);
    return answer;
}