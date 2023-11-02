#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
            answer = false;
    }

    if (s.length() == 4 || s.length() == 6)
    {
        if(answer)
            return true;
    }
    else
    {
        return false;
    }
    return answer;
}