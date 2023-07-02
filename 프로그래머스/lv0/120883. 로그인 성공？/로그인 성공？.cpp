#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    for(const auto id_pw_arr : db)
    {
        if(id_pw_arr[0] == id_pw[0])
        {
            if(id_pw_arr[1] == id_pw[1])
            {
                answer = "login";                
            }
            else
            {
                answer = "wrong pw";
            }
            return answer;
        }
    }
    
    answer = "fail";
    return answer;
}