#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> chk;
    string tmp="";
    for(const auto c : s)
    {
        if(c != ' ')
          tmp += c;
            
        else if(c == ' ')
        {
            if(tmp.size())
            {
                chk.push_back(stoi(tmp));
                tmp="";
            }
        }
    }
    if(tmp.size())
    {
         chk.push_back(stoi(tmp));
         tmp="";
    }
    
    sort(chk.begin(), chk.end());
    
    answer += to_string(chk.front());
    answer += ' ';
    answer += to_string(chk.back());
    return answer;
}