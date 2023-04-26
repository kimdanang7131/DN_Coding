#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(auto c : myString)
    {
        answer+=toupper(c);
    }
    return answer;
}