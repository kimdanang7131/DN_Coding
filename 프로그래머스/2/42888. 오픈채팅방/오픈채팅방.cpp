#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> accountUserMap;
    map<int,string> exitMap;
    
    stringstream ss;

    for(int i=0; i < record.size(); i++)
    {
        string exit      = "";
        string accountID = "";
        string userID    = "";
        
        ss.clear();
        ss.str(record[i]);
        
        ss >> exit >> accountID >> userID;
            
        if(exit == "Enter")
        {
            answer.push_back("님이 들어왔습니다.");
            exitMap[answer.size()-1] = accountID;
            
            accountUserMap[accountID] = userID;
        }
        else if(exit == "Leave")
        {
            answer.push_back("님이 나갔습니다.");
            exitMap[answer.size()-1] = accountID;
        }
        else if(exit == "Change")
        {
            accountUserMap[accountID] = userID;
        }
        
    }
    
    
    for(int i=0; i < answer.size(); i++)
        answer[i] = accountUserMap[exitMap[i]] + answer[i];
    
    return answer;
}