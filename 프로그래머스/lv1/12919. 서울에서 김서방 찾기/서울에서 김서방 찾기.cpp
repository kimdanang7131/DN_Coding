#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int kim = 0;
    
    for(int i=0; i<seoul.size(); i++)
    {
        if(seoul[i].find("Kim") != string::npos)
        {
            kim = i;
            break;
        }
    }
    
    answer += "김서방은 ";
    answer += to_string(kim);
    answer += "에 있다";
    return answer;
}