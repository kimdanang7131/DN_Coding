#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";

    for (auto a : alp)
    {
        for (auto& c : my_string)
        {
            if ((c == a) && (c >= 97 && c <= 122))
            {
                c = toupper(c);
            }
        }
    }
    
    answer = my_string;
    return answer;
    }